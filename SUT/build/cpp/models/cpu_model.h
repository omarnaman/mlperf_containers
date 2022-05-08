#ifndef CPU_MODEL_H_
#define CPU_MODEL_H_

#include <cassert>
#include <chrono>
#include <cmath>
#include <random>
#include <string>
#include <iostream>
#include "model.h"

struct CPUQueryParam {
  u_int64_t runtime;
};

struct CPUQueryResponse {
  uint64_t time_taken;
  int error_code;
};

class CPUModel : public BaseModel<CPUQueryParam, CPUQueryResponse> {
 public:
  CPUQueryParam parseQuery(const std::string& query) override {
    const char* p = query.data();
    CPUQueryParam params;
    params.runtime = *((u_int64_t*)p);
    return params;
  }
  std::string runQuery(const CPUQueryParam& queryParameters) override {
    uint64_t runtime = 0;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    double numerator = rand();
    double denomirator = 2 * asin(1);
    while (runtime < queryParameters.runtime) {
      start = std::chrono::system_clock::now();
      for (int i = 0; i < 10000; i++) {
        numerator /= denomirator;
      }
      end = std::chrono::system_clock::now();
      runtime += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    std::cout << runtime << "\n";
    CPUQueryResponse response;
    response.error_code = 0;
    response.time_taken = runtime;
    
    return serializeResponse(response);
  }
  std::string serializeResponse(const CPUQueryResponse& response) override {
    std::string ser_res;
    ser_res.assign((char*)&response, sizeof(CPUQueryResponse));
    return ser_res;
  }
};
#endif  // CPU_MODEL_H_