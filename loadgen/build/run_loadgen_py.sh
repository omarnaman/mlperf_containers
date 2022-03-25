source ./setup_tc.sh $@

set -- ${NONTC[@]}
# SUT_address SUT_port Storage_address Storage_port Experiment_name Selector
sut_address=$1;
sut_port=$2;
storage_address=$3;
storage_port=$4;
eid=$5;
selector=$6;
shift 6;
output=`pwd`/output/onnxruntime-cpu/ssd-mobilenet
python3 python/py_loadgen/main.py \
 --backend onnxruntime \
 --model-name ssd-mobilenet \
 --profile ssd-mobilenet-onnxruntime \
 --output $output \
 --dataset-path `pwd`/python/coco_300 \
 --mlperf_conf mlperf.conf \
 --max-batchsize 8 \
 --address "$sut_address:$sut_port" \
 --threads 8 \
 $@ && \
\
python3 store_results.py "$eid" "$selector" "$output" "http://$storage_address:$storage_port"
