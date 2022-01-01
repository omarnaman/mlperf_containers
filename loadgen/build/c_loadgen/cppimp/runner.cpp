#include "runner.h"

#include <unistd.h>

#include <string>
#include <vector>

#include "../loadgen.h"
#include "../query_sample.h"
#include "../query_sample_library.h"
#include "dataset.h"
#include "lib/basic_client.h"

RunnerBase::RunnerBase(Dataset* dataset) {
  puts("RunnerBase Constructor");
  this->dataset = dataset;
  queries_sent = 0;
}
RunnerBase::~RunnerBase() { puts("RunnerRemote Constructor"); }

void RunnerBase::runQuery(const std::vector<mlperf::QuerySample>& samples) {
  std::vector<mlperf::QuerySampleResponse> responses;
  for (auto i = samples.begin(); i != samples.end(); i++) {
    Data* item = dataset->getSample(i->index);
    mlperf::QuerySampleResponse r = predict(item);
    r.id = i->id;
    responses.push_back(r);
  }
  for (size_t i = 0; i < 5; i++) {
    queries_sent++;
    mlperf::QuerySamplesComplete(responses.data(), responses.size());
  }
}
mlperf::QuerySampleResponse RunnerRemote::predict(const Data* item) {
  int res = client->predict(item->data, item->size);
  if (res) {
    std::cerr << "Yikes\n";
  }
  return mlperf::QuerySampleResponse{
      .id = 0, .data = (uintptr_t)item->data, .size = item->size};
}

std::string RunnerRemote::targetString() {
  std::stringstream ss;
  ss << remote_address << ":" << remote_port;
  return ss.str();
}

RunnerRemote::RunnerRemote(const std::string& address, const ushort& port,
                           Dataset* dataset)
    : RunnerBase(dataset), remote_address(address), remote_port(port) {
  puts("RunnerRemote Constructor");
  client = new BasicServiceClient(
      grpc::CreateChannel(targetString(), grpc::InsecureChannelCredentials()));
}

RunnerRemote::~RunnerRemote() { puts("RunnerRemote Constructor"); }

SleepRunner::SleepRunner(Dataset* dataset) : RunnerBase(dataset) {
  puts("SleepRunner Constructor");
}
SleepRunner::~SleepRunner() {}
mlperf::QuerySampleResponse SleepRunner::predict(const Data* item) {
  printf("Sleeping for %d us\n", *(int*)item->data);
  usleep(*(int*)item->data);
  return mlperf::QuerySampleResponse{
      .id = 0, .data = (uintptr_t)item->data, .size = item->size};
}