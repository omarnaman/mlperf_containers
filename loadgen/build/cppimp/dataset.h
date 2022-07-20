#ifndef DMLPERF_DATASET_H
#define DMLPERF_DATASET_H

#include <stdint.h>

#include <string>
#include <vector>
#include "../c_loadgen/dataset.h"

class SyntheticDataset : public mlperf::Dataset {
 private:
  size_t number_of_samples;
 public:
  SyntheticDataset(size_t number_of_samples);
  ~SyntheticDataset();

  void loadDataset() override;

  mlperf::Data* getSample(const int& index) override;
  size_t getNumberOfSamples() override;

};

class StringDataset : public mlperf::Dataset {
 private:
  size_t number_of_samples;

 public:
  StringDataset(size_t number_of_samples);
  ~StringDataset();

  void loadDataset() override;
  mlperf::Data* getSample(const int& index) override;
  size_t getNumberOfSamples() override;
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
  void postProcess(const char* data, size_t size, const char* label) override;
  size_t getNumberOfSamples() override;
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
  size_t getNumberOfSamples() override;
};

#endif
