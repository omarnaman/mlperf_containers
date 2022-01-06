#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <iostream>
#include <memory>
#include <mutex>
#include <string>

#include "basic.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;

// Logic and data behind the server's behavior.
class BasicServiceImpl final : public BasicService::Service {
  Status InferenceItem(ServerContext* context, const RequestItem* request,
                       ItemResult* reply) override {
    std::string s = request->items();
    std::cout << "Got item: " << *(int*)s.data() << std::endl;
    reply->set_results(s.data(), s.size());
    reply->set_id(request->id());
    return Status::OK;
  }

  Status StreamInferenceItem(
      ServerContext* context,
      ServerReaderWriter<ItemResult, RequestItem>* stream) override {
    RequestItem requestItem;
    while (stream->Read(&requestItem)) {
      ItemResult itemResult;
      std::string s = requestItem.items();
      std::cout << "Got item: " << *(int*)s.data()
                << " with id: " << requestItem.id() << std::endl;
      itemResult.set_results(s.data(), s.size());

      itemResult.set_id(requestItem.id());
      stream->Write(itemResult);
    }

    return Status::OK;
  }

 private:
  std::mutex mt;
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  BasicServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
