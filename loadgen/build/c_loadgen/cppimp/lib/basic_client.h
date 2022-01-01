#ifndef DMLPERF_GRPC_BASIC_CLIENT_H
#define DMLPERF_GRPC_BASIC_CLIENT_H

#include <iostream>
#include <memory>
#include <string>
#include <stdint.h>
#include <grpcpp/grpcpp.h>


#include "basic.grpc.pb.h"


using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


class BasicServiceClient {
 public:
  BasicServiceClient(std::shared_ptr<Channel> channel);
  int predict(const char* items, const size_t size);

 private:
  std::unique_ptr<BasicService::Stub> stub_;
};

#endif