
#ifndef MODEL_H_
#define MODEL_H_



#include <string>


template <class QueryParam, class Response>
class BaseModel {
 private:
 public:
  virtual QueryParam parseQuery(const std::string& query) = 0;
  virtual std::string runQuery(const QueryParam& queryParameters) = 0;
  virtual std::string serializeResponse(const Response& response) = 0;
};



#endif  // MODEL_H_