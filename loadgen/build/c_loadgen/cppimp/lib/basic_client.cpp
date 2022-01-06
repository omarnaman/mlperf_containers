#include "basic_client.h"

#include <condition_variable>
#include <mutex>
#include <utility>
#include <sstream>
#include <cli_colors.h>
#include "basic.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReaderWriter;
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

BasicServiceClientStreamer::BasicServiceClientStreamer(
    std::shared_ptr<Channel> channel)
    : stub_(BasicService::NewStub(channel)),
      stream(stub_->StreamInferenceItem(&context)) {
  puts("Client Streamer Constructor");
  senderThread = new std::thread([this] { sendRequests(); });
  receiverThread = new std::thread([this] { receiveResponse(); });
}

void BasicServiceClientStreamer::sendRequests() {
  const char* items = NULL;
  size_t size = 0;
  uintptr_t id = 0;
  const RequestData* requestData;
  puts("sendRequests Started");
  while (true) {
    {
      std::unique_lock<std::mutex> lk(requestMt);
      requestPushed.wait(lk, [this]() { return this->hasRequests(); });
      clic::color_print("sendRequests got an item", clic::CYAN);
      requestData = requestQueue.front();
      requestQueue.pop();
    }
    items = requestData->items;
    size = requestData->size;
    id = requestData->id;
    std::cout << "Sending Item with id: " << id << std::endl;
    RequestItem requestItem;
    requestItem.set_items(items, size);
    requestItem.set_id(id);
    stream->Write(requestItem);
    puts("item sent");
  }
}
void BasicServiceClientStreamer::sendRequest(const RequestData* items) {
  std::lock_guard<std::mutex> lk(requestMt);
  requestQueue.push(items);
  // puts("Request Pushed");
  std::stringstream ss;
  ss << "Request Pushed with ID: " << items->id;
  clic::color_print(ss.str(), clic::RED);
  
  requestPushed.notify_one();
}

bool BasicServiceClientStreamer::hasRequests() { return !requestQueue.empty(); }
bool BasicServiceClientStreamer::hasResponses() {
  return !responseQueue.empty();
}

void BasicServiceClientStreamer::receiveResponse() {
  ItemResult itemResult;
  while (stream->Read(&itemResult)) {
    std::lock_guard<std::mutex> lk(responseMt);
    puts("Got Response");
    responseQueue.push(RequestData{
        .items = NULL, .size = 0, .id = itemResult.id()});
    responsePushed.notify_one();
  }
}

RequestData BasicServiceClientStreamer::getResponse() {
  std::unique_lock<std::mutex> lk(responseMt);
  responsePushed.wait(lk, [this]() { return this->hasResponses(); });
  RequestData responseData = responseQueue.front();
  std::cout << "received Item with id: " << responseData.id << std::endl;

  responseQueue.pop();
  return responseData;
}
