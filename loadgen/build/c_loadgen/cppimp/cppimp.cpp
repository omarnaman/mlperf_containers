
#include <unistd.h>

#include <iostream>
#include <map>
#include <string>

#include "../loadgen.h"
#include "../query_sample_library.h"
#include "../system_under_test.h"
#include "../test_settings.h"
#include "dataset.h"
#include "sut.h"
#include "lib/basic.grpc.pb.h"

using namespace mlperf;

int main() {
  TestSettings testSettings;
  LogSettings logSettings;
  testSettings.scenario = TestScenario::SingleStream;
  testSettings.mode = TestMode::PerformanceOnly;
  testSettings.single_stream_expected_latency_ns = 10000;
  testSettings.min_query_count = 100;
  testSettings.min_duration_ms = 10000;

  ushort port = 50051;
  std::string address = "localhost";
  Dataset* dataset = new SyntheticDataset();
  RunnerBase* runner = new RunnerRemote(address, port, dataset);
  SystemUnderTest* sut = new SUT(runner);
  QuerySampleLibrary* qsl = new QSL(1024, 128);
  StartTest(sut, qsl, testSettings, logSettings);
  // delete runner;
  delete sut;
  delete qsl;
  return 0;
}