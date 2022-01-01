#include "dataset.h"

#include <dirent.h>

#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

Dataset::Dataset() { datapoints = new std::vector<Data*>(); }
Dataset::~Dataset() {
  for (auto&& point : *datapoints) {
    delete point;
  }
  delete datapoints;
};

SyntheticDataset::SyntheticDataset(){};
SyntheticDataset::~SyntheticDataset(){};
void SyntheticDataset::load_dataset() { return; }

Data* SyntheticDataset::get_sample(const int& index) {
  Data* res = new Data();
  res->data = (char*)new int(10);
  res->size = sizeof(int);
  res->label = 0;
  return res;
}
StringDataset::StringDataset(){};
StringDataset::~StringDataset(){};
void StringDataset::load_dataset() { return; }

Data* StringDataset::get_sample(const int& index) {
  Data* res = new Data();
  res->data = new char[10];
  res->size = 10 * sizeof(char);
  res->data = "123456789\0";
  res->label = 0;
  return res;
}

CocoDataset::CocoDataset(std::string& labels_path, std::string& image_dir){
  this->image_dir = "coco/images/";//image_dir;
  this->labels_path = "coco/lables";
};
CocoDataset::~CocoDataset(){};
std::vector<std::string> CocoDataset::list_dir(const std::string& dir_path) {
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

void CocoDataset::load_dataset() {
  std::ifstream labels_file, image_file;
  std::map<std::string, int> labels_map;
  labels_file.open(labels_path);
  std::string image_name;
  int label;
  while (labels_file >> image_name >> label) {
    labels_map[image_name] = label;
  }
  std::vector<std::string> image_list = list_dir(image_dir);
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
    datapoints->push_back(item);
  }

  return;
}

Data* CocoDataset::get_sample(const int& index) {
  assert(index < datapoints->size());
  return datapoints->at(index);
}