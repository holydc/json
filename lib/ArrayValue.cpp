#include "./ArrayValue.h"

#include <sstream>

namespace json {
ArrayValue::ArrayValue(std::vector<Value> value)
    : value_(std::move(value)) {
}

std::string ArrayValue::stringify() const {
  std::ostringstream oss;
  oss << '[';
  for (size_t i = 0; i < value_.size(); ++i) {
    if (i > 0) {
      oss << ',';
    }
    oss << value_[i].stringify();
  }
  oss << ']';
  return oss.str();
}
} // namespace json
