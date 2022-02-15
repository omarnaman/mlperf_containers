#ifndef DMLPERF_GRPC_BASIC_CLIENT_H
#define DMLPERF_GRPC_BASIC_CLIENT_H

#include <grpcpp/grpcpp.h>
#include <stdint.h>

#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <thread>
#include <condition_variable>
#include "basic.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReaderWriter;
using grpc::Status;

struct RequestData{
  char* items;
  size_t size;
  uintptr_t id;
};

class BasicServiceClient {
 public:
  BasicServiceClient(std::shared_ptr<Channel> channel);
  RequestData* predict(const char* items, const size_t size, uintptr_t id);

 private:
  std::unique_ptr<BasicService::Stub> stub_;
};

class BasicServiceClientStreamer {
 public:
  BasicServiceClientStreamer(std::shared_ptr<Channel> channel);
  void sendRequest(const RequestData* items);
  void receiveResponse();
  bool hasRequests();
  bool hasResponses();
  RequestData getResponse();

 private:
  void sendRequests();
  std::thread* senderThread;
  std::thread* receiverThread;
  std::queue<const RequestData*> requestQueue;
  std::queue<RequestData> responseQueue;
  std::mutex requestMt;
  std::mutex responseMt;
  std::condition_variable responsePushed;
  std::condition_variable requestPushed;
  ClientContext context;
  std::unique_ptr<BasicService::Stub> stub_;
  std::shared_ptr< ClientReaderWriter<RequestItem, ItemResult> > stream;
};

#endif