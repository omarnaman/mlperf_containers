source ./setup_tc.sh $@

set -- ${NONTC[@]}
# SUT_address SUT_port Storage_address Storage_port File_storage_address File_storage_port Experiment_name Selector Config_ID
sut_address=$1;
sut_port=$2;
storage_address=$3;
storage_port=$4;
file_storage_address=$5;
file_storage_port=$6;
eid=$7;
selector=$8;
config_id=$9;
shift 9;
output=`pwd`/cppimp/build

wget "http://$file_storage_address:$file_storage_port/$config_id" --output-document=cppimp/build/mlperf.conf

cd cppimp/build && ./loadgen SingleStream $sut_address $sut_port && \
\
cd ../../ && python3 store_results.py "$eid" "$selector" "$output" "http://$storage_address:$storage_port"
