#ifndef IO_MODEL_H_
#define IO_MODEL_H_

#include <string>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <cassert>
#include <cmath>

#include "model.h"

struct IOQueryParam {
  size_t file_size;
  size_t burst_size;
  bool fsync;
};

struct IOQueryResponse {
  uint64_t time_taken;
  int error_code;
};

class IOModel : public BaseModel<IOQueryParam, IOQueryResponse> {
 public:
  IOQueryParam parseQuery(const std::string& query) override {
    const char* p = query.data();
    IOQueryParam params;
    params.file_size = *((size_t*)p);
    p += sizeof(size_t);
    params.burst_size = *((size_t*)p);
    p += sizeof(size_t);
    params.fsync = *((size_t*)p);
    p += sizeof(bool);
    return params;
  }
  std::string runQuery(const IOQueryParam& queryParameters) override {
    int out = open("tmpfile", O_SYNC | O_TRUNC | O_CREAT | O_WRONLY);
    assert(out > 0);
    size_t written_bytes = 0;
    ssize_t written = 0;
    const char* data = new char[queryParameters.burst_size];
    while (written_bytes < queryParameters.file_size) {
      size_t to_write = std::min(queryParameters.file_size - written_bytes, queryParameters.burst_size);

      if (queryParameters.fsync) {
        written = write(out, data, to_write);
        assert(written > 0);
      }
      written_bytes += written;
    }

    delete data;
    IOQueryResponse response;
    response.error_code = 0;
    response.time_taken = 0;
    return serializeResponse(response);
  }
  std::string serializeResponse(const IOQueryResponse& response) override {
    std::string ser_res;
    ser_res.assign((char*)&response, sizeof(IOQueryResponse));
    return ser_res;
  }
};
#endif // IO_MODEL_H_