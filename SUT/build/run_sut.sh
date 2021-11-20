source ./setup_tc.sh $@

set -- ${NONTC[@]}
python3 /workspace/python/main.py $@