#include "./StringValue.h"

#include <sstream>

namespace json {
StringValue::StringValue(std::string value)
    : value_(std::move(value)) {
}

std::string StringValue::stringify() const {
  std::ostringstream oss;
  oss << '"' << value_ << '"';
  return oss.str();
}
} // namespace json
