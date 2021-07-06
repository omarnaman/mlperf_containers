#!/usr/bin/env python3

import basic_pb2
import basic_pb2_grpc
import grpc
import pickle
import numpy as np
import os

import threading
import asyncio

import cli_colors
import time
import signal

from concurrent import futures

def get_backend(backend):
    if backend == "tensorflow":
        from backend_tf import BackendTensorflow
        backend = BackendTensorflow()
    elif backend == "onnxruntime":
        from backend_onnxruntime import BackendOnnxruntime
        backend = BackendOnnxruntime()
    elif backend == "null":
        from backend_null import BackendNull
        backend = BackendNull()
    elif backend == "pytorch":
        from backend_pytorch import BackendPytorch
        backend = BackendPytorch()
    elif backend == "pytorch-native":
        from backend_pytorch_native import BackendPytorchNative
        backend = BackendPytorchNative()
    elif backend == "tflite":
        from backend_tflite import BackendTflite
        backend = BackendTflite()
    else:
        raise ValueError("unknown backend: " + backend)
    return backend

time_taken = []

class BasicServiceServicer(basic_pb2_grpc.BasicServiceServicer):
    model = None
    def __init__(self, backend, model_path, inputs, outputs) -> None:
        self.model = backend.load(model_path, inputs=inputs, outputs=outputs)
        super().__init__()

    async def InferenceItem(self, request: basic_pb2.RequestItem, context: grpc.ServicerContext):
        # cli_colors.color_print("Inference Item", cli_colors.CYAN_SHADE2)
        global time_taken
        s = time.time()
        items = pickle.loads(request.items)
        results = self.model.predict({self.model.inputs[0]: items})
        results = pickle.dumps(results, protocol=0)
        response: basic_pb2.ItemResult = basic_pb2.ItemResult(results=results)
        e = time.time()
        
        time_taken.append(e-s)
        # cli_colors.color_print("Ended inferencing", cli_colors.CYAN_SHADE1)
        return response


async def serve():
    model_path = os.path.join(os.environ["MODEL_DIR"], "mobilenet_v1_1.0_224.onnx")
    backend = get_backend("onnxruntime")
    server = grpc.aio.server(futures.ThreadPoolExecutor(max_workers=10))
    basic_pb2_grpc.add_BasicServiceServicer_to_server(
        BasicServiceServicer(backend, model_path, None, ['MobilenetV1/Predictions/Reshape_1:0']), server)
    server.add_insecure_port('[::]:8086')
    await server.start()
    await server.wait_for_termination()

def safe_exit(signum, frame):
    global time_taken
    cli_colors.color_print(f"total: {sum(time_taken)}, avg: {(sum(time_taken)/len(time_taken)):5f}")
    exit(1)

if __name__ == '__main__':
    signal.signal(signal.SIGINT, safe_exit)
    asyncio.run(serve())