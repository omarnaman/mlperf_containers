#ifndef DMLPERF_SUT_H
#define DMLPERF_SUT_H

#include <vector>
#include <thread>


#include "../c_loadgen/query_sample_library.h"
#include "../c_loadgen/system_under_test.h"
#include "runner.h"
#include "dataset.h"

using namespace mlperf;
class SUT : public SystemUnderTest {
 public:
  const std::string& Name() const override;
  void IssueQuery(const std::vector<QuerySample>& samples) override;
  void FlushQueries() override;
  void ReportLatencyResults(
      const std::vector<QuerySampleLatency>& latencies_ns) override;
  SUT(RunnerBase* runner, size_t n_threads);
  ~SUT();

 private:
  std::string name;
  std::vector<std::thread> threads;
};

class QSL : public QuerySampleLibrary {
 public:
  const std::string& Name() const override;
  size_t TotalSampleCount();
  size_t PerformanceSampleCount();

  void LoadSamplesToRam(const std::vector<QuerySampleIndex>& samples) override;
  void UnloadSamplesFromRam(
      const std::vector<QuerySampleIndex>& samples) override;

  QSL(size_t performance_sample_count, Dataset* dataset);

  ~QSL();

 private:
  std::string name;
  Dataset* dataset;
  size_t total_sample_count;
  size_t performance_sample_count;
};

#endif