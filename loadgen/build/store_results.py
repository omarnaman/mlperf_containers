import json
import pandas
import sys
import requests
import os

def upload_qps(eid, selector):
    with open("results.json", "r") as f:
        data = json.load(f)

    for k in data.keys():
        if k.startswith("Test"):
            qps = data[k]["qps"]
    
    url = "http://storage:8082/qps"
    request_data = {
            "qps": qps,
            "experiment_id": eid,
            "selector": selector
            }
    req = requests.post(url, json=request_data)


def upload_latencies(eid, selector, path):
    df = pandas.read_csv(os.path.join(path, "communication.csv"), index_col=0)
    lats = df.loc[0:, "0"].tolist()
    url = "http://storage:8082/latencies"
    request_data = {
            "latencies": lats,
            "experiment_id": eid,
            "selector": selector
            }
    req = requests.post(url, json=request_data)

def main():
    eid = sys.argv[1]
    selector = sys.argv[2]
    path = sys.argv[3]
    upload_qps(eid, selector)
    upload_latencies(eid, selector, path)


if __name__ == "__main__":
    main()
