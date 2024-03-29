// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: basic.proto

#include "basic.pb.h"
#include "basic.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* BasicService_method_names[] = {
  "/BasicService/InferenceItem",
  "/BasicService/StreamInferenceItem",
  "/BasicService/ChangeThreads",
};

std::unique_ptr< BasicService::Stub> BasicService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< BasicService::Stub> stub(new BasicService::Stub(channel, options));
  return stub;
}

BasicService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_InferenceItem_(BasicService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_StreamInferenceItem_(BasicService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  , rpcmethod_ChangeThreads_(BasicService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BasicService::Stub::InferenceItem(::grpc::ClientContext* context, const ::RequestItem& request, ::ItemResult* response) {
  return ::grpc::internal::BlockingUnaryCall< ::RequestItem, ::ItemResult, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_InferenceItem_, context, request, response);
}

void BasicService::Stub::async::InferenceItem(::grpc::ClientContext* context, const ::RequestItem* request, ::ItemResult* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::RequestItem, ::ItemResult, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_InferenceItem_, context, request, response, std::move(f));
}

void BasicService::Stub::async::InferenceItem(::grpc::ClientContext* context, const ::RequestItem* request, ::ItemResult* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_InferenceItem_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ItemResult>* BasicService::Stub::PrepareAsyncInferenceItemRaw(::grpc::ClientContext* context, const ::RequestItem& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ItemResult, ::RequestItem, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_InferenceItem_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ItemResult>* BasicService::Stub::AsyncInferenceItemRaw(::grpc::ClientContext* context, const ::RequestItem& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncInferenceItemRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReaderWriter< ::RequestItem, ::ItemResult>* BasicService::Stub::StreamInferenceItemRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::RequestItem, ::ItemResult>::Create(channel_.get(), rpcmethod_StreamInferenceItem_, context);
}

void BasicService::Stub::async::StreamInferenceItem(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::RequestItem,::ItemResult>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::RequestItem,::ItemResult>::Create(stub_->channel_.get(), stub_->rpcmethod_StreamInferenceItem_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::RequestItem, ::ItemResult>* BasicService::Stub::AsyncStreamInferenceItemRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::RequestItem, ::ItemResult>::Create(channel_.get(), cq, rpcmethod_StreamInferenceItem_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::RequestItem, ::ItemResult>* BasicService::Stub::PrepareAsyncStreamInferenceItemRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::RequestItem, ::ItemResult>::Create(channel_.get(), cq, rpcmethod_StreamInferenceItem_, context, false, nullptr);
}

::grpc::Status BasicService::Stub::ChangeThreads(::grpc::ClientContext* context, const ::ThreadRequest& request, ::ThreadReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::ThreadRequest, ::ThreadReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ChangeThreads_, context, request, response);
}

void BasicService::Stub::async::ChangeThreads(::grpc::ClientContext* context, const ::ThreadRequest* request, ::ThreadReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::ThreadRequest, ::ThreadReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ChangeThreads_, context, request, response, std::move(f));
}

void BasicService::Stub::async::ChangeThreads(::grpc::ClientContext* context, const ::ThreadRequest* request, ::ThreadReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ChangeThreads_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ThreadReply>* BasicService::Stub::PrepareAsyncChangeThreadsRaw(::grpc::ClientContext* context, const ::ThreadRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ThreadReply, ::ThreadRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ChangeThreads_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ThreadReply>* BasicService::Stub::AsyncChangeThreadsRaw(::grpc::ClientContext* context, const ::ThreadRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncChangeThreadsRaw(context, request, cq);
  result->StartCall();
  return result;
}

BasicService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BasicService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BasicService::Service, ::RequestItem, ::ItemResult, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BasicService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::RequestItem* req,
             ::ItemResult* resp) {
               return service->InferenceItem(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BasicService_method_names[1],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< BasicService::Service, ::RequestItem, ::ItemResult>(
          [](BasicService::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::ItemResult,
             ::RequestItem>* stream) {
               return service->StreamInferenceItem(ctx, stream);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BasicService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BasicService::Service, ::ThreadRequest, ::ThreadReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BasicService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::ThreadRequest* req,
             ::ThreadReply* resp) {
               return service->ChangeThreads(ctx, req, resp);
             }, this)));
}

BasicService::Service::~Service() {
}

::grpc::Status BasicService::Service::InferenceItem(::grpc::ServerContext* context, const ::RequestItem* request, ::ItemResult* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BasicService::Service::StreamInferenceItem(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::ItemResult, ::RequestItem>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BasicService::Service::ChangeThreads(::grpc::ServerContext* context, const ::ThreadRequest* request, ::ThreadReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


