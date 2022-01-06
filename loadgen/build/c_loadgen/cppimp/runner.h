#ifndef DMLPERF_RUNNER_H
#define DMLPERF_RUNNER_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "../query_sample.h"
#include "dataset.h"
#include "lib/basic_client.h"
#include "lib/thread_queue.h"
class RunnerBase {
 protected:
 public:
  int queries_sent;
  Dataset* dataset;
  RunnerBase(Dataset* dataset);
  ~RunnerBase();
  virtual mlperf::QuerySampleResponse predict(const Data* item) = 0;
  virtual void runQuery(const std::vector<mlperf::QuerySample>& samples);
};

class RunnerRemote : public RunnerBase {
 protected:
  std::string remote_address;
  ushort remote_port;
  BasicServiceClient* client;

 public:
  RunnerRemote(const std::string& address, const ushort& port,
               Dataset* dataset);
  ~RunnerRemote();
  virtual mlperf::QuerySampleResponse predict(const Data* item) override;
  std::string targetString();
};

class RemoteStreamer : public RunnerBase {
 private:
  std::string remote_address;
  ushort remote_port;
  std::thread* sender;
  std::thread* receiver;
  std::mutex mt;
  std::condition_variable cv;
  BasicServiceClientStreamer* clientStreamer;

 public:
  RemoteStreamer(const std::string& address, const ushort& port,
                 Dataset* dataset);
  ~RemoteStreamer();
  // mlperf::QuerySampleResponse predict(const Data* item) override;
  virtual void runQuery(
      const std::vector<mlperf::QuerySample>& samples) override;
  virtual mlperf::QuerySampleResponse predict(const Data* item) override;
  void receiveData();
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