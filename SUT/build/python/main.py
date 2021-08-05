#!/usr/bin/env python3

from typing import List
import basic_pb2
import basic_pb2_grpc
import grpc
import pickle

# TODO: replace with typer
import argparse

import json
import time
from enum import Enum
from concurrent import futures
import os


class Task(str, Enum):
    DownloadModel = 'download'
    Serve = 'serve'


def download_model(task_args: List[str]):
    import model_downloader
    parser = argparse.ArgumentParser()
    parser.add_argument('--runtime', type=str, help="The runtime of the model")
    parser.add_argument('--model', type=str, help="The model to serve")
    parser.add_argument('--model-out', type=str, help="The path to save the model")
    args = parser.parse_args(task_args)
    runtime = args.runtime
    model = args.model
    full_data = model_downloader.download_model(runtime, model)
    with open(args.model_out, 'wb') as f:
        f.write(full_data)


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


class BasicServiceServicer(basic_pb2_grpc.BasicServiceServicer):
    model = None
    def __init__(self, backend, model_path, inputs, outputs, threads=0) -> None:
        self.model = backend.load(model_path, inputs=inputs, outputs=outputs, threads=threads)
        self.model_path = model_path
        self.backend = backend
        self.outputs = outputs
        self.inputs = inputs
        self.threads = threads
        super().__init__()

    def InferenceItem(self, request: basic_pb2.RequestItem, context: grpc.ServicerContext):
        items = pickle.loads(request.items)
        s = time.time()
        results = self.model.predict({self.model.inputs[0]: items})
        e = time.time()
        results = pickle.dumps((results, e-s), protocol=0)
        response: basic_pb2.ItemResult = basic_pb2.ItemResult(results=results)
        return response
    
    def ChangeThreads(self, request, context):
        n = request.threads
        if n == self.threads:
            return basic_pb2.ThreadReply(ok=True)
        self.model = self.backend.load(self.model_path, self.inputs, self.outputs, n)
        
        self.threads = n
        return basic_pb2.ThreadReply(ok=True)



def get_args(extra_args: List[str]):
    parser = argparse.ArgumentParser()
    parser.add_argument("--model-threads", type=int, default=0,
                        help="the number of threads the model should run for inferencing a single query")
    parser.add_argument("--model-path", type=str, help="the path to the model", required=False)
    parser.add_argument("--model", type=str, help="the name of the model to serve", required=False)
    parser.add_argument("--runtime", type=str, help="the runtime name", default="onnxruntime")
    args = parser.parse_args(extra_args)
    print(args)
    if args.model_path is None and args.model is None:
        raise Exception("Either --model-path or --model needs to be provided")
    return args

def serve(extra_args: List[str]):
    args = get_args(extra_args)
    runtime = args.runtime
    if args.model_path is not None:
        model_path = args.model_path
    else:
        model_path = args.model
    if not os.path.exists(model_path):
        print("Model not found, downloading...")
        if args.model is None:
            raise Exception("Model name not provided")
        model = args.model
        download_model(["--model", model, "--runtime", runtime, "--model-out", model_path])
            
    backend = get_backend(runtime)
    print("Listening on [0.0.0.0:8086]...")
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=32))
    basic_pb2_grpc.add_BasicServiceServicer_to_server(
        BasicServiceServicer(backend, model_path, None, ['num_detections:0','detection_boxes:0','detection_scores:0','detection_classes:0'], threads=args.model_threads), server)
    server.add_insecure_port('0.0.0.0:8086')
    server.start()
    server.wait_for_termination()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('mlcube_task', type=str, help="Task for this MLCube.")
    # parser.add_argument('--log_dir', '--log-dir', type=str, required=True, help="Logging directory.")
    mlcube_args, extra_args = parser.parse_known_args()
    task = mlcube_args.mlcube_task

    if task == Task.DownloadModel:
        download_model(extra_args)
        exit()
    
    if task == Task.Serve:
        serve(extra_args)

if __name__ == '__main__':
    main()