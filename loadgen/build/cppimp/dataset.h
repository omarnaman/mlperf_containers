#ifndef DMLPERF_DATASET_H
#define DMLPERF_DATASET_H

#include <stdint.h>

#include <string>
#include <vector>
#include "../c_loadgen/dataset.h"

class SyntheticDataset : public mlperf::Dataset {
 private:
 public:
  SyntheticDataset();
  ~SyntheticDataset();

  void loadDataset() override;

  mlperf::Data* getSample(const int& index) override;
};

class StringDataset : public mlperf::Dataset {
 private:
 public:
  StringDataset();
  ~StringDataset();

  void loadDataset() override;
  mlperf::Data* getSample(const int& index) override;
};

class CocoDataset : public mlperf::Dataset {
 private:
  std::string labelsPath = "coco/lables";
  std::string imageDir = "coco/images/";
  std::vector<std::string> listDir(const std::string& dir_path);
  std::vector<std::string>* dataPointPath;

 public:
  CocoDataset(std::string& labels_path, std::string& image_dir);
  ~CocoDataset();

  void loadDataset() override;
  void loadSamples(const std::vector<size_t>& samples) override;
  mlperf::Data* getSample(const int& index) override;
  void postProcess(const char* data, size_t size) override;
};

class PreprocessedDataset : public mlperf::Dataset {
 private:
  std::vector<std::string> listDir(const std::string& dir_path);
  std::vector<std::string>* dataPointPath;
  std::string dataPath;

 public:
  PreprocessedDataset(std::string& data_dir);
  ~PreprocessedDataset();

  void loadDataset() override;
  void loadSamples(const std::vector<size_t>& samples) override;
  mlperf::Data* getSample(const int& index) override;
};

#endif
