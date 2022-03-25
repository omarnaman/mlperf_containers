source ./setup_tc.sh $@

set -- ${NONTC[@]}
# SUT_address SUT_port Storage_address Storage_port Experiment_name Selector
sut_address=$1;
sut_port=$2;
storage_address=$3;
storage_port=$4;
eid=$5;
selector=$6;
output=`pwd`/cppimp/build
shift 6;

cd cppimp/build && ./loadgen $sut_address $sut_port && \
\
cd ../../ && python3 store_results.py "$eid" "$selector" "$output" "http://$storage_address:$storage_port"
