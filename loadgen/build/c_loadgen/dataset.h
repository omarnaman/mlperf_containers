#ifndef DMLPERF_DATASET_BASE_H
#define DMLPERF_DATASET_BASE_H

#include <stdint.h>

#include <vector>
namespace mlperf {

struct Data {
  char* data;
  size_t size;
  int label;
  uintptr_t id;
};

class Dataset {
 public:
  std::vector<Data*>* dataPoints;
  Dataset();
  ~Dataset();
  virtual void loadDataset() = 0;
  virtual void loadSamples(const std::vector<size_t>& samples){};
  virtual Data* getSample(const int& index) = 0;
  virtual void postProcess(const char* data, size_t size = 0){};
};

}  // namespace mlperf
#endif
