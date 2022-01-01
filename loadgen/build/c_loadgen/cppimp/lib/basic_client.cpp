#include "basic.grpc.pb.h"
#include "basic_client.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


  BasicServiceClient::BasicServiceClient(std::shared_ptr<Channel> channel)
      : stub_(BasicService::NewStub(channel)) {}

  int BasicServiceClient::predict(const char* items, const size_t size) {
    RequestItem request;
    request.set_items((char*)items, size);
    request.set_id(0);
    ItemResult reply;

    ClientContext context;

    Status status = stub_->InferenceItem(&context, request, &reply);

    if (status.ok()) {
      return 0;
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return 1;
    }
  }
