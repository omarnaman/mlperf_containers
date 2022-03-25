
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

int main(int args, char** argv) {
  const size_t THREADS = 1;
  TestSettings testSettings;
  LogSettings logSettings;
  testSettings.scenario = TestScenario::SingleStream;
  testSettings.mode = TestMode::PerformanceOnly;
  testSettings.single_stream_expected_latency_ns = 100000;
  testSettings.min_query_count = 1;
  testSettings.min_duration_ms = 10000;
  testSettings.server_num_issue_query_threads = 0;
  testSettings.generic_num_issue_query = THREADS;

  if(args < 3){
    std::cerr << argv[0] << " <SUT address> <SUT port>\n";
  }
  ushort port = atoi(argv[2]);
  std::string address = argv[1];
  std::string labels_path = "coco/labels.txt";
  std::string images_path = "coco/images";
  std::string uspp_path = "uspp_processed";

  Dataset* dataset = new CocoDataset(labels_path, images_path);
  // Dataset* dataset = new SyntheticDataset();
  RunnerBase* runner = new RunnerRemote(address, port, dataset);
  // RunnerBase* runner = new SleepRunner(dataset);
  SystemUnderTest* sut = new SUT(runner, THREADS);
  QuerySampleLibrary* qsl = new QSL(1024, 128, dataset);

  puts("Starting Test");
  StartTest(sut, qsl, testSettings, logSettings);
  // delete runner;
  delete sut;
  delete qsl;
  return 0;
}