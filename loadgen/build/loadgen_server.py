#!/bin/env python3

import flask
import os
import sys

import store_results

app = flask.Flask(__name__)

DATASET_URL = ''
# aws s3 cp "$dataset_URL" cppimp/build/dataset.tar.gz && \
# tar -xzf cppimp/build/dataset.tar.gz -C cppimp/build/

def download_dataset(url):
    os.system(f'aws s3 cp {url} cppimp/build/dataset.tar.gz && tar -xzf cppimp/build/dataset.tar.gz -C cppimp/build/')


# Experiment_name Selector SUT_address Storage_address File_storage_address Config_ID Dataset_URL Scenario
@app.route('/run_expriement', methods=['POST'])
def start_lg():
    global DATASET_URL
    json_data = flask.request.get_json()
    experiment_name = json_data['experiment_name']
    eid = experiment_name
    selector = json_data['selector']
    sut_address = json_data['sut_address']
    storage_address = json_data['storage_address']
    file_storage_address = json_data['file_storage_address']
    config_id = json_data['config_id']
    dataset_url = json_data['dataset_url']
    scenario = json_data['scenario']
    output=os.path.join(os.getcwd(), "cppimp/build")

    os.system(f'wget "http://{file_storage_address}/{config_id}" --output-document=cppimp/build/mlperf.conf')
    
    if dataset_url != DATASET_URL:
        download_dataset(dataset_url)
        DATASET_URL = dataset_url

    # cd cppimp/build && ./loadgen $scenario $sut_address
    os.system(f'cd cppimp/build && ./loadgen {scenario} {sut_address}')
    # cd ../../ && python3 store_results.py "$eid" "$selector" "$output" "http://$storage_address"
    os.system(f'python3 store_results.py {experiment_name} {sut_address} {output} {storage_address}')

    qps, latencies = store_results.process_summary(output)
    store_results.upload_qps(eid, selector, qps, storage_address)
    store_results.upload_latencies(eid, selector, latencies, storage_address)

@app.route('/stop')
def exit_flask():
    sys.exit(0)


if __name__=="__main__":
    app.run(host='0.0.0.0', port=8088)