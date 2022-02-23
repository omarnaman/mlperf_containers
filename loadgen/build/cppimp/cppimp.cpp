
#include <unistd.h>

#include <iostream>
#include <map>
#include <string>
#include <thread>

#include "../c_loadgen/loadgen.h"
#include "../c_loadgen/query_sample_library.h"
#include "../c_loadgen/system_under_test.h"
#include "../c_loadgen/test_settings.h"
#include "dataset.h"
#include "sut.h"
#include "lib/basic.grpc.pb.h"

using namespace mlperf;

int main() {
  const size_t THREADS = 0;
  TestSettings testSettings;
  LogSettings logSettings;
  testSettings.scenario = TestScenario::SingleStream;
  testSettings.mode = TestMode::PerformanceOnly;
  testSettings.single_stream_expected_latency_ns = 10000000000;
  testSettings.min_query_count = 1;
  testSettings.min_duration_ms = 10000;
  testSettings.server_num_issue_query_threads = 0;
  testSettings.generic_num_issue_query = THREADS;

  ushort port = 8086;
  std::string address = "localhost";
  std::string labels_path = "coco/labels.txt";
  std::string images_path = "coco/images";
  std::string uspp_path = "uspp_processed";

  Dataset* dataset = new PreprocessedDataset(uspp_path);
  // Dataset* dataset = new SyntheticDataset();
  RunnerBase* runner = new RunnerRemote(address, port, dataset);
  // RunnerBase* runner = new SleepRunner(dataset);
  SystemUnderTest* sut = new SUT(runner, THREADS);
  QuerySampleLibrary* qsl = new QSL(5, 2, dataset);

  puts("Starting Test");
  StartTest(sut, qsl, testSettings, logSettings);
  // delete runner;
  delete sut;
  delete qsl;
  return 0;
}