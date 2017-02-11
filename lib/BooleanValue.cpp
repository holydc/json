#include "./BooleanValue.h"

namespace json {
BooleanValue::BooleanValue(bool value)
    : value_(value) {
}

std::string BooleanValue::stringify() const {
  return value_ ? "true" : "false";
}
} // namespace json
