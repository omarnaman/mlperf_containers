source ./setup_tc.sh $@

set -- ${NONTC[@]}
sut=$1;
port=$2;
name=$3;
output=`pwd`/output/onnxruntime-cpu/ssd-mobilenet
shift 3;

cd cppimp/build && ./loadgen $sut $port 
