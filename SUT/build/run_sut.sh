source ./setup_tc.sh $@

set -- ${NONTC[@]}
python3 ./python/main.py $@