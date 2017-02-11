#include "./ObjectValue.h"

#include <sstream>

namespace json {
ObjectValue::ObjectValue(std::unordered_map<std::string, Value> value)
    : value_(std::move(value)) {
}

std::string ObjectValue::stringify() const {
  auto begin = value_.begin();
  auto end = value_.end();
  std::ostringstream oss;
  oss << '{';
  for (auto i = begin; i != end; ++i) {
    if (i != begin) {
      oss << ',';
    }
    oss << '"' << i->first << "\":" << i->second.stringify();
  }
  oss << '}';
  return oss.str();
}
} // namespace json
