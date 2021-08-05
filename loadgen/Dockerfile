FROM ubuntu:20.04

# Remove all stopped containers: docker rm $(docker ps -a -q)
# Remove containers like none:none: docker rmi $(docker images | grep none | awk '{print $3}')


WORKDIR /workspace/loadgen/

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
            python3-dev \
            python3-pip \
            build-essential \
            git \
            wget \
            python3-opencv \
            cmake \
            build-essential \ 
            unzip zip \
            sed \
            curl

RUN rm -rf /var/lib/apt/lists/*


COPY build /workspace/loadgen/build/
COPY requirements.txt /requirements.txt

# install pip packages
RUN pip3 install --no-cache-dir -r /requirements.txt

# install pybind11
RUN git clone https://github.com/pybind/pybind11.git && \
    cp -r pybind11/include/pybind11 /usr/include && \
    rm -rf pybind11

# install loadgen
RUN cd /workspace/loadgen/build/c_loadgen && \
    FLAGS="-std=c++14" python3 setup.py install
    # rm -rf c_loadgen

# generate dataset
RUN cd /workspace/loadgen/build/python/tools && \
    [ -f val2017.zip ] || wget -q http://images.cocodataset.org/zips/val2017.zip && \
    [ -f annotations_trainval2017.zip ] || wget -q http://images.cocodataset.org/annotations/annotations_trainval2017.zip && \
    unzip val2017.zip && \
    unzip annotations_trainval2017.zip && \
    python3 ./upscale_coco.py --inputs . --outputs ../coco_300 --size 300 300 --format png && \
    rm val2017.zip annotations_trainval2017.zip && \
    rm -rf val2017 annotations

# Start loadgen
WORKDIR /workspace/loadgen/build
ENTRYPOINT ["bash", "./run_loadgen.sh", "sut:8086"]
