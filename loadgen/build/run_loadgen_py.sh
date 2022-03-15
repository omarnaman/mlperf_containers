source ./setup_tc.sh $@

set -- ${NONTC[@]}
sut=$1;
name=$2;
output=`pwd`/output/onnxruntime-cpu/ssd-mobilenet
selector=$3;
shift 3;
python3 python/py_loadgen/main.py \
 --backend onnxruntime \
 --model-name ssd-mobilenet \
 --profile ssd-mobilenet-onnxruntime \
 --output $output \
 --dataset-path `pwd`/python/coco_300 \
 --mlperf_conf mlperf.conf \
 --max-batchsize 8 \
 --address $sut \
 --threads 8 \
 $@ && \
\
cat "$output"/results.json | sed "s;\(\".*\)\(\.\)\(.*\"\);\1_\3;" > results.json && \
# curl -X PUT -d "@results.json" https://mlperf-c8f1a-default-rtdb.firebaseio.com/`date +%s`_"$name".json
python3 store_results.py "$name" "$selector" "$output"
