#include "./object.h"

#include <sstream>

namespace json {
ObjectValue::ObjectValue(std::initializer_list<std::pair<const std::string, json::Value>> value)
  : value_(std::move(value)) {
}

std::string ObjectValue::stringify() const {
  const char *separator = "";
  std::ostringstream oss;
  oss << '{';
  for (const auto &value : value_) {
    oss << separator << '"' << value.first << "\":" << value.second.stringify();
    separator = ",";
  }
  oss << '}';
  return oss.str();
}
} // namespace json
