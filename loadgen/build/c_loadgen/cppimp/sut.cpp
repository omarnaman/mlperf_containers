#include "sut.h"

#include <unistd.h>

#include <iostream>

#include "../loadgen.h"
#include "../query_sample_library.h"
#include "../system_under_test.h"
#include "runner.h"
using namespace mlperf;

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
  std::cout << "Reporting results\n" << runner->queries_sent << "\n";
}
SUT::SUT(RunnerBase* runner) {
  name = "sut_cpp";
  this->runner = runner;
}
SUT::~SUT() {}

// QSL implementation

const std::string& QSL::Name() const { return name; }
size_t QSL::TotalSampleCount() { return total_sample_count; }
size_t QSL::PerformanceSampleCount() { return performance_sample_count; }

void QSL::LoadSamplesToRam(const std::vector<QuerySampleIndex>& samples) {}
void QSL::UnloadSamplesFromRam(const std::vector<QuerySampleIndex>& samples) {}

QSL::QSL(size_t total_sample_count, size_t performance_sample_count) {
  this->total_sample_count = total_sample_count;
  this->performance_sample_count = performance_sample_count;
  name = "qsl_cpp";
};

QSL::~QSL() {}
