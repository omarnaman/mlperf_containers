
#include <unistd.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <thread>

#include "../c_loadgen/loadgen.h"
#include "../c_loadgen/query_sample_library.h"
#include "../c_loadgen/system_under_test.h"
#include "../c_loadgen/test_settings.h"
#include "dataset.h"
#include "lib/basic.grpc.pb.h"
#include "sut.h"

using namespace mlperf;

TestScenario GetScenario(std::string& string_scenario) {
  if (!string_scenario.compare("SingleStream")) {
    return TestScenario::SingleStream;
  } else if (!string_scenario.compare("MultiStream")) {
    return TestScenario::MultiStream;
  } else if (!string_scenario.compare("MultiStreamFree")) {
    return TestScenario::MultiStreamFree;
  } else if (!string_scenario.compare("Server")) {
    return TestScenario::Server;
  } else if (!string_scenario.compare("Offline")) {
    return TestScenario::Offline;
  }
}

int main(int args, char** argv) {
  TestSettings testSettings;
  LogSettings logSettings;

  if (args < 3) {
    std::cerr << argv[0] << "<Scenario> <SUT address>\n";
  }
  std::string model = "Coco";  // TODO: read from args
  std::string string_scenario = argv[1];
  TestScenario testScenario = GetScenario(string_scenario);

  std::string address = argv[2];
  std::string conf_path = "mlperf.conf";
  testSettings.FromConfig(conf_path, string_scenario, model);
  testSettings.scenario = testScenario;
  const size_t THREADS = testSettings.generic_num_issue_query;
  std::string labels_path = "coco/labels.txt";
  std::string images_path = "coco/images";
  std::string uspp_path = "uspp_processed";

  Dataset* dataset = new CocoDataset(labels_path, images_path);
  RunnerBase* runner = new RunnerRemote(address, dataset);
  SystemUnderTest* sut = new SUT(runner, THREADS);
  QuerySampleLibrary* qsl = new QSL(128, dataset);

  puts("Starting Test");
  StartTest(sut, qsl, testSettings, logSettings);
  // delete runner;
  delete sut;
  delete qsl;
  return 0;
}