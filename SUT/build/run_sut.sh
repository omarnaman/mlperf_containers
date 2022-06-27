source ./setup_tc.sh $@
# args: Model_URl tar.gz_file
model_url=$1
shift;

wget $model_url -O model.tar.gz
tar -xzf model.tar.gz -C ./model

set -- ${NONTC[@]}
python3 ./python/main.py $@ --model-path=model