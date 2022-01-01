#ifndef DMLPERF_DATASET_H
#define DMLPERF_DATASET_H

#include <stdint.h>
#include <string>

#include <vector>
struct Data {
  char* data;
  size_t size;
  int label;
};
class Dataset {
 public:
  std::vector<Data*>* dataPoints;
  Dataset();
  ~Dataset();
  virtual void loadDataset() = 0;
  virtual Data* getSample(const int& index) = 0;
};

class SyntheticDataset : public Dataset {
 private:
 public:
  SyntheticDataset();
  ~SyntheticDataset();

  void loadDataset() override;
  Data* getSample(const int& index) override;
};

class StringDataset : public Dataset {
 private:
 public:
  StringDataset();
  ~StringDataset();

  void loadDataset() override;
  Data* getSample(const int& index) override;
};

class CocoDataset : public Dataset {
 private:
  std::string labelsPath = "coco/lables";
  std::string imageDir = "coco/images/";
  std::vector<std::string> listDir(const std::string& dir_path);
 public:
  CocoDataset(std::string& labels_path, std::string& image_dir);
  ~CocoDataset();

  void loadDataset() override;
  Data* getSample(const int& index) override;
};

#endif
