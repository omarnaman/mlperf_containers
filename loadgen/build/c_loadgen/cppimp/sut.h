#ifndef DMLPERF_SUT_H
#define DMLPERF_SUT_H

#include "../query_sample_library.h"
#include "../system_under_test.h"
#include "runner.h"

using namespace mlperf;
class SUT : public SystemUnderTest {
 public:
  const std::string& Name() const override;
  void IssueQuery(const std::vector<QuerySample>& samples) override;
  void FlushQueries() override;
  void ReportLatencyResults(
      const std::vector<QuerySampleLatency>& latencies_ns) override;
  SUT(RunnerBase* runner);
  ~SUT();

 private:
  std::string name;
  RunnerBase* runner;
};

class QSL : public QuerySampleLibrary {
 public:
  const std::string& Name() const override;
  size_t TotalSampleCount();
  size_t PerformanceSampleCount();

  void LoadSamplesToRam(const std::vector<QuerySampleIndex>& samples) override;
  void UnloadSamplesFromRam(
      const std::vector<QuerySampleIndex>& samples) override;

  QSL(size_t total_sample_count, size_t performance_sample_count);

  ~QSL();

 private:
  std::string name;
  size_t total_sample_count;
  size_t performance_sample_count;
};

#endif