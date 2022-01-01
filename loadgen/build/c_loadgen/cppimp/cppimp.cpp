
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
  TestSettings test_settings;
  LogSettings log_settings;
  test_settings.scenario = TestScenario::SingleStream;
  test_settings.mode = TestMode::PerformanceOnly;
  test_settings.single_stream_expected_latency_ns = 10000;
  test_settings.min_query_count = 100;
  test_settings.min_duration_ms = 10000;

  ushort port = 50051;
  std::string address = "localhost";
  Dataset* dataset = new SyntheticDataset();
  RunnerBase* runner = new RunnerRemote(address, port, dataset);
  SystemUnderTest* sut = new SUT(runner);
  QuerySampleLibrary* qsl = new QSL(1024, 128);
  StartTest(sut, qsl, test_settings, log_settings);
  // delete runner;
  delete sut;
  delete qsl;
  return 0;
}