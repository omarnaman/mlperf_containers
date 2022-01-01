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
  std::vector<Data*>* datapoints;
  Dataset();
  ~Dataset();
  virtual void load_dataset() = 0;
  virtual Data* get_sample(const int& index) = 0;
};

class SyntheticDataset : public Dataset {
 private:
 public:
  SyntheticDataset();
  ~SyntheticDataset();

  void load_dataset() override;
  Data* get_sample(const int& index) override;
};

class StringDataset : public Dataset {
 private:
 public:
  StringDataset();
  ~StringDataset();

  void load_dataset() override;
  Data* get_sample(const int& index) override;
};

class CocoDataset : public Dataset {
 private:
  std::string labels_path = "coco/lables";
  std::string image_dir = "coco/images/";
  std::vector<std::string> list_dir(const std::string& dir_path);
 public:
  CocoDataset(std::string& labels_path, std::string& image_dir);
  ~CocoDataset();

  void load_dataset() override;
  Data* get_sample(const int& index) override;
};

#endif
