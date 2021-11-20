FROM ubuntu:20.04

# To be built from parent directory

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
            python3-dev \
            python3-pip \
            python3-opencv \
            iproute2 && \
    rm -rf /var/lib/apt/lists/*

COPY SUT/requirements.txt /requirements.txt
RUN pip3 install --no-cache-dir -r /requirements.txt

COPY SUT/build /workspace/build/
COPY common/setup_tc.sh /workspace/build/
COPY common/grpc_proto/*.py /workspace/build/python/

WORKDIR /workspace/build
ENTRYPOINT ["bash", "./run_sut.sh", "serve", "--model", "ssd-mobilenet"]