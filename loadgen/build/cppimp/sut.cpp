#include "sut.h"

#include <unistd.h>

#include <iostream>

#include "../c_loadgen/loadgen.h"
#include "../c_loadgen/query_sample_library.h"
#include "../c_loadgen/system_under_test.h"
#include "runner.h"
using namespace mlperf;

// void StartIssueThread() {
//     RegisterIssueQueryThread();
// }

// SUT implementation
const std::string& SUT::Name() const { return name; }
void SUT::IssueQuery(const std::vector<QuerySample>& samples) {
  runner->runQuery(samples);
  // // std::cout << "Sent a query\n";
  // std::vector<QuerySampleResponse> responses;
  // for (size_t i = 0; i < samples.size(); i++) {
  //   QuerySampleResponse response;
  //   response.id = samples[i].id;
  //   response.data = NULL;
  //   response.size = 0;
  //   usleep(10);
  //   responses.push_back(response);
  // }

  // QuerySamplesComplete(responses.data(), responses.size());
}
void SUT::FlushQueries() { std::cout << "Flushed queries\n"; }
void SUT::ReportLatencyResults(
    const std::vector<QuerySampleLatency>& latencies_ns) {
  std::cout << "Reporting results\n";
}
SUT::SUT(RunnerBase* runner, size_t n_threads) {
  name = "sut_cpp";
  this->runner = runner;
  for (size_t i = 0; i < n_threads; i++) {
    threads.emplace_back(RegisterIssueQueryThread);
  }
}
SUT::~SUT() {
  for (auto&& thread : threads) {
    thread.join();
  }
}

// QSL implementation

const std::string& QSL::Name() const { return name; }
size_t QSL::TotalSampleCount() { return total_sample_count; }
size_t QSL::PerformanceSampleCount() { return performance_sample_count; }

void QSL::LoadSamplesToRam(const std::vector<QuerySampleIndex>& samples) {
  printf("Loading into ram %u samples\n", samples.size());
  this->dataset->loadSamples(samples);
}
void QSL::UnloadSamplesFromRam(const std::vector<QuerySampleIndex>& samples) {}

QSL::QSL(size_t performance_sample_count,
         Dataset* dataset) {
  this->total_sample_count = dataset->getNumberOfSamples();
  this->performance_sample_count = performance_sample_count;
  this->dataset = dataset;
  name = "qsl_cpp";
};

QSL::~QSL() {}
