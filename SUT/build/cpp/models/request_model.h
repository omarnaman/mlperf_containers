#ifndef REQUEST_MODEL_H_
#define REQUEST_MODEL_H_

#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "model.h"

struct ReqQueryParam {
  u_int64_t sleep_time;  // in Microseconds
};

struct ReqQueryResponse {
  uint64_t time_taken;
  int error_code;
};

class RequestModel : public BaseModel<ReqQueryParam, ReqQueryResponse> {
 public:
  ReqQueryParam parseQuery(const std::string& query) override {
    const char* p = query.data();
    ReqQueryParam params;
    params.sleep_time = *((u_int64_t*)p);
    return params;
  }

  auto awake_time(u_int64_t sleep_time) {
    return std::chrono::steady_clock::now() + std::chrono::microseconds(sleep_time);
  }
  std::string runQuery(const ReqQueryParam& queryParameters) override {
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::this_thread::sleep_until(awake_time(queryParameters.sleep_time));

    end = std::chrono::system_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "\n";

    ReqQueryResponse response;
    response.error_code = 0;
    response.time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    return serializeResponse(response);
  }
  std::string serializeResponse(const ReqQueryResponse& response) override {
    std::string ser_res;
    ser_res.assign((char*)&response, sizeof(ReqQueryResponse));
    return ser_res;
  }
};
#endif  // REQUEST_MODEL_H_