"""
tensorflow backend (https://github.com/tensorflow/tensorflow)
"""

# pylint: disable=unused-argument,missing-docstring,useless-super-delegation

import tensorflow as tf
from tensorflow.core.framework import dtypes
from tensorflow.python.tools.optimize_for_inference_lib import optimize_for_inference

import os
import backend


class BackendTensorflow(backend.Backend):
    def __init__(self):
        super(BackendTensorflow, self).__init__()

    def version(self):
        return tf.__version__ + "/" + tf.__git_version__

    def name(self):
        return "tensorflow"

    def image_format(self):
        # By default tensorflow uses NHWC (and the cpu implementation only does NHWC)
        return "NHWC"

    def load(self, model_path, inputs=None, outputs=None, shape=300, threads=0):
        # there is no input/output meta data i the graph so it need to come from config.
        if not inputs:
            raise ValueError("BackendTensorflow needs inputs")
        if not outputs:
            raise ValueError("BackendTensorflow needs outputs")
        self.outputs = outputs
        self.inputs = inputs

        infer_config = tf.compat.v1.ConfigProto()
        infer_config.intra_op_parallelism_threads = int(os.environ['TF_INTRA_OP_PARALLELISM_THREADS']) \
                if 'TF_INTRA_OP_PARALLELISM_THREADS' in os.environ else os.cpu_count()
        infer_config.inter_op_parallelism_threads = int(os.environ['TF_INTER_OP_PARALLELISM_THREADS']) \
                if 'TF_INTER_OP_PARALLELISM_THREADS' in os.environ else os.cpu_count()
        infer_config.use_per_session_threads = threads

        # Load SavedModel from directory
        if tf.io.gfile.isdir(model_path):
            # load from directory
            self.sess = tf.compat.v1.Session(config=infer_config)
            self.shape = (1, int(shape), int(shape), 3)
            tf.compat.v1.saved_model.load(self.sess, [tf.saved_model.SERVING], model_path)
            return self

        # TODO: support checkpoint and saved_model formats?
        graph_def = tf.compat.v1.GraphDef()
        with tf.compat.v1.gfile.FastGFile(model_path, "rb") as f:
            graph_def.ParseFromString(f.read())
        for as_datatype_enum in [dtypes.float32.as_datatype_enum, dtypes.uint8.as_datatype_enum]:
            try:
                optimized_graph_def = optimize_for_inference(graph_def, [item.split(':')[0] for item in inputs],
                        [item.split(':')[0] for item in outputs], as_datatype_enum, False)
                graph_def = optimized_graph_def
                break
            except (ValueError, KeyError):
                pass

        g = tf.compat.v1.import_graph_def(graph_def, name='')
        self.sess = tf.compat.v1.Session(graph=g, config=infer_config)
        self.shape = (1, int(shape), int(shape), 3)
        return self


    def parse_query(self, items: bytes) -> np.ndarray:

        items = np.frombuffer(items, np.uint8)
        items.shape = self.shape

        return items

    def serialize_response(self, res: list) -> bytes:
        """
        (1,)        float32 number of objects
        (1, 100, 4) float32 bounding boxes
        (1, 100)    float32 confidence
        (1, 100)    float32 classes (labels)
        """
        # results = res[0].tobytes() + res[2].tobytes() + res[3].tobytes() + res[1].tobytes()
        return b""
        # return results

    def predict(self, feed):
        return self.sess.run(self.outputs, feed_dict=feed)
