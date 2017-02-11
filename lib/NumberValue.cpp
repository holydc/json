#include "./NumberValue.h"

namespace json {
NumberValue::NumberValue(double value)
    : value_(value) {
}

std::string NumberValue::stringify() const {
  return std::to_string(value_);
}
} // namespace json
