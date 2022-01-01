#include "dataset.h"

#include <dirent.h>

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

Dataset::Dataset() { dataPoints = new std::vector<Data*>(); }
Dataset::~Dataset() {
  for (auto&& point : *dataPoints) {
    delete point;
  }
  delete dataPoints;
};

SyntheticDataset::SyntheticDataset(){};
SyntheticDataset::~SyntheticDataset(){};
void SyntheticDataset::loadDataset() { return; }

Data* SyntheticDataset::getSample(const int& index) {
  Data* res = new Data();
  res->data = (char*)new int(10);
  res->size = sizeof(int);
  res->label = 0;
  return res;
}
StringDataset::StringDataset(){};
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

CocoDataset::CocoDataset(std::string& labelsPath, std::string& imageDir) {
  this->imageDir = "coco/images/";  // imageDir;
  this->labelsPath = "coco/lables";
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

void CocoDataset::loadDataset() {
  std::ifstream labels_file, image_file;
  std::map<std::string, int> labels_map;
  labels_file.open(labelsPath);
  std::string image_name;
  int label;
  while (labels_file >> image_name >> label) {
    labels_map[image_name] = label;
  }
  std::vector<std::string> image_list = listDir(imageDir);
  Data* item;
  for (auto&& image : image_list) {
    item = new Data();
    image_file.open(image, std::ios::binary | std::ios::ate);
    item->size = image_file.tellg();
    image_file.seekg(0, std::ios::beg);
    item->data = new char[item->size];
    image_file.read((char*)item->data, item->size);
    std::map<std::string, int>::iterator iter = labels_map.find(image);
    if (iter == labels_map.end()) {
      std::cerr << "No label found for: " << image << std::endl;
      delete item;
    }
    item->label = iter->second;
    dataPoints->push_back(item);
  }

  return;
}

Data* CocoDataset::getSample(const int& index) {
  assert(index < dataPoints->size());
  return dataPoints->at(index);
}