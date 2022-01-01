#ifndef DMLPERF_RUNNER_H
#define DMLPERF_RUNNER_H

#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "../query_sample.h"
#include "dataset.h"
#include "lib/basic_client.h"
class RunnerBase {
 protected:
  Dataset* dataset;

 public:
  int queries_sent;
  RunnerBase(Dataset* dataset);
  ~RunnerBase();
  virtual mlperf::QuerySampleResponse predict(const Data* item) = 0;
  virtual void runQuery(const std::vector<mlperf::QuerySample>& indices);
};

class RunnerRemote : public RunnerBase {
 private:
  std::string remote_address;
  ushort remote_port;
  BasicServiceClient* client;

 public:
  RunnerRemote(const std::string& address, const ushort& port,
               Dataset* dataset);
  ~RunnerRemote();
  mlperf::QuerySampleResponse predict(const Data* item) override;
  std::string targetString();
};

class SleepRunner : public RunnerBase {
 private:
 public:
  SleepRunner(Dataset* dataset);
  ~SleepRunner();
  mlperf::QuerySampleResponse predict(const Data* item) override;
};

#endif