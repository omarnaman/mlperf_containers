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


class Task(str, Enum):
    DownloadModel = 'download'
    Serve = 'serve'


def download_model(task_args: List[str]):
    import model_downloader
    parser = argparse.ArgumentParser()
    parser.add_argument('--runtime', type=str, help="The model to serve")
    parser.add_argument('--model', type=str, help="The model to serve")
    parser.add_argument('--model_out', type=str, help="The output file of the model")
    parser.add_argument('--runtime_out', type=str, help="The output file of the runtime")
    args = parser.parse_args(task_args)
    with open(args.runtime, 'r') as f:
        runtime = f.read()
    with open(args.model, 'r') as f:
        model = f.read()
    full_data = model_downloader.download_model(runtime, model)
    with open(args.model_out, 'wb') as f:
        f.write(full_data)
    with open(args.runtime_out, 'w') as f:
        f.write(runtime.strip())


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
    parser.add_argument("--model", type=str, help="the path to the model")
    parser.add_argument("--runtime", type=str, help="the path to the file that contains the runtime name")
    args = parser.parse_args(extra_args)
    return args

def serve(extra_args: List[str]):
    args = get_args(extra_args)
    model_path = args.model
    with open(args.runtime, 'r') as f:
        runtime = f.read()
    # os.path.join(os.environ["MODEL_DIR"], "ssd_mobilenet_v1_coco_2018_01_28.onnx")
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