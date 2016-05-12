#include "./number.h"

#include <sstream>

namespace json {
NumberValue::NumberValue(double value) : value_(value) {
}

std::string NumberValue::stringify() const {
  std::ostringstream oss;
  oss << value_;
  return oss.str();
}
} // namespace json
