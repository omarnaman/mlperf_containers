FROM ubuntu:20.04

# Remove all stopped containers: docker rm $(docker ps -a -q)
# Remove containers like none:none: docker rmi $(docker images | grep none | awk '{print $3}')

EXPOSE 8086

WORKDIR /workspace/python/

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
            python3-dev \
            python3-pip \
            python3-opencv  && \
    rm -rf /var/lib/apt/lists/*

COPY requirements.txt /requirements.txt
RUN pip3 install --no-cache-dir -r /requirements.txt

COPY python /workspace/python/

# defult parameter to ENTRYPOINT 
# CMD  ["10"]

ENTRYPOINT ["python3", "/workspace/python/main.py"]