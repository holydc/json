#include "./array.h"

#include <sstream>

namespace json {
ArrayValue::ArrayValue(std::initializer_list<Value> value) : value_(std::move(value)) {
}

std::string ArrayValue::stringify() const {
  const char *separator = "";
  std::ostringstream oss;
  oss << '[';
  for (const auto &value : value_) {
    oss << separator << value.stringify();
    separator = ",";
  }
  oss << ']';
  return oss.str();
}
} // namespace json
