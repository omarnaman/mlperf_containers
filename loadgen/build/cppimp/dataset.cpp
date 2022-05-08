#include "dataset.h"

#include <dirent.h>
#include <memory.h>
#include <unistd.h>

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace mlperf;

/* Synthetic Dataset Implementation*/
#pragma region SyntheticDataset
SyntheticDataset::SyntheticDataset(size_t number_of_samples) {
  this->number_of_samples = number_of_samples;
};
SyntheticDataset::~SyntheticDataset(){};
void SyntheticDataset::loadDataset() { return; }

Data* SyntheticDataset::getSample(const int& index) {
  Data* res = new Data();
  res->data = (char*)new int(10);
  res->size = sizeof(int);
  res->label = 0;
  return res;
}

size_t SyntheticDataset::getNumberOfSamples() {
  return number_of_samples;
};

#pragma endregion SyntheticDataset

/* String Dataset Implementation*/
#pragma region StringDataset

StringDataset::StringDataset(size_t number_of_samples) {
  this->number_of_samples = number_of_samples;
};
StringDataset::~StringDataset(){};
void StringDataset::loadDataset() { return; }

Data* StringDataset::getSample(const int& index) {
  Data* res = new Data();
  res->data = new char[10];
  res->size = 10 * sizeof(char);
  res->data = "123456789\0";
  res->label = 0;
  return res;
}

size_t StringDataset::getNumberOfSamples() {
  return number_of_samples;
};
#pragma endregion StringDataset


// TODO: let Coco dataset and all the other file-oriented 
//  datasets inheret from the same base class

/* Coco Dataset Implementation*/
#pragma region CocoDataset
CocoDataset::CocoDataset(std::string& labelsPath, std::string& imageDir) {
  this->imageDir = imageDir;  // imageDir;
  this->labelsPath = labelsPath;
  this->dataPointPath = new std::vector<std::string>();
  loadDataset();
};
CocoDataset::~CocoDataset(){};
std::vector<std::string> CocoDataset::listDir(const std::string& dirPath) {
  DIR* dir_fd = opendir(dirPath.c_str());
  std::vector<std::string> filelist;
  if (!dir_fd) {
    std::cerr << "Im dead lol\n";
    return filelist;
  }
  dirent* file;
  while (file = readdir(dir_fd)) {
    if (file->d_type == DT_REG) {
      filelist.push_back(std::string(file->d_name));
    }
  }

  return filelist;
}

size_t CocoDataset::getNumberOfSamples() {
  return dataPoints->size();
};

void CocoDataset::loadDataset() {
  char tmp[1000];
  getcwd(tmp, 999);
  std::ifstream labels_file, image_file;
  std::map<std::string, int> labels_map;
  labels_file.open(labelsPath, std::ios::in);
  assert(labels_file.is_open());
  std::string image_name;
  int label;
  while (labels_file >> image_name >> label) {
    labels_map[image_name] = label;
  }
  std::vector<std::string> image_list = listDir(imageDir);
  Data* item;
  for (auto&& image : image_list) {
    std::map<std::string, int>::iterator iter = labels_map.find(image);
    if (iter == labels_map.end()) {
      std::cerr << "No label found for: " << image << std::endl;
      continue;
    }
    this->dataPointPath->push_back(imageDir + "/" + image);
    item = new Data();
    memset(item, 0, sizeof(item));
    image_file.open(this->dataPointPath->back(),
                    std::ios::binary | std::ios::ate);
    assert(image_file.is_open());
    item->size = image_file.tellg();
    item->data = NULL;
    item->label = iter->second;
    dataPoints->push_back(item);
    image_file.close();
  }
  return;
}

Data* CocoDataset::getSample(const int& index) {
  if (index > dataPoints->size()) {
    std::cout << index << " is outside the bounds on dataPoints\n";
  }
  assert(index < dataPoints->size());
  return dataPoints->at(index);
}
void CocoDataset::loadSamples(const std::vector<size_t>& samples) {
  Data* item;
  std::ifstream image_file;

  for (auto&& index : samples) {
    assert(index < this->dataPointPath->size());
    item = this->dataPoints->at(index);
    assert(item);
    image_file.open(this->dataPointPath->at(index),
                    std::ios::binary | std::ios::in);
    assert(image_file.is_open());
    item->data = new char[item->size];
    image_file.read((char*)item->data, item->size);
    image_file.close();
  }
}

void CocoDataset::postProcess(const char* data, size_t size) {
  float* data_float = (float*)data;
  float noi = *data_float++;

  std::vector<std::vector<float>> bounding;
  std::vector<float> confidence;
  std::vector<float> label;

  confidence.assign(data_float, data_float + 100);
  data_float += 100;
  label.assign(data_float, data_float + 100);
  data_float += 100;
  for (int i = 0; i < noi; i++) {
    bounding.push_back(std::vector<float>());
    bounding[i].assign(data_float, data_float + 4);
    data_float += 4;
  }
  std::cout << "Detected " << noi << " objects\n";
  std::cout << "confidence " << confidence[0] << "\n";
  std::cout << "label " << label[0] << "\n";
  if (noi) {
    std::cout << "bounding x " << bounding[0][0] << "\n";
  }
}
#pragma endregion CocoDataset

/* Preprocessed Dataset Implementation*/
#pragma region Preprocessed

PreprocessedDataset::PreprocessedDataset(std::string& data_dir) {
  this->dataPath = data_dir;
  this->dataPointPath = new std::vector<std::string>();
  loadDataset();
};

PreprocessedDataset::~PreprocessedDataset(){};
std::vector<std::string> PreprocessedDataset::listDir(
    const std::string& dir_path = "uspp_processed") {
  DIR* dir_fd = opendir(dir_path.c_str());
  std::vector<std::string> filelist;
  if (!dir_fd) {
    std::cerr << "Im dead lol\n";
    return filelist;
  }
  dirent* file;
  while (file = readdir(dir_fd)) {
    if (file->d_type == DT_REG) {
      filelist.push_back(std::string(file->d_name));
    }
  }

  return filelist;
}

size_t PreprocessedDataset::getNumberOfSamples() {
  return dataPoints->size();
};

void PreprocessedDataset::loadDataset() {
  char tmp[1000];
  getcwd(tmp, 999);
  std::ifstream data_file;
  std::map<std::string, int> labels_map;
  std::string datapoint_name;
  int label;
  std::vector<std::string> datapoint_list = listDir(dataPath);
  Data* item;
  for (auto&& datapointPath : datapoint_list) {
    this->dataPointPath->push_back(dataPath + "/" + datapointPath);
    item = new Data();
    memset(item, 0, sizeof(item));
    data_file.open(this->dataPointPath->back(),
                   std::ios::binary | std::ios::ate);
    assert(data_file.is_open());
    item->size = data_file.tellg();
    item->data = NULL;
    item->label = 0;
    dataPoints->push_back(item);
    data_file.close();
  }
  return;
}

Data* PreprocessedDataset::getSample(const int& index) {
  if (index > dataPoints->size()) {
    std::cout << index << " is outside the bounds on dataPoints\n";
  }
  assert(index < dataPoints->size());
  return dataPoints->at(index);
}
void PreprocessedDataset::loadSamples(const std::vector<size_t>& samples) {
  Data* item;
  std::ifstream image_file;

  for (auto&& index : samples) {
    assert(index < this->dataPointPath->size());
    item = this->dataPoints->at(index);
    assert(item);
    image_file.open(this->dataPointPath->at(index),
                    std::ios::binary | std::ios::in);
    assert(image_file.is_open());
    item->data = new char[item->size];
    image_file.read((char*)item->data, item->size);
    image_file.close();
  }
}

#pragma endregion Preprocessed
