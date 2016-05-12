#include "./string.h"

#include <sstream>

namespace json {
StringValue::StringValue(std::string value) : value_(std::move(value)) {
}

StringValue::StringValue(const char *value) : value_(value) {
}

StringValue::StringValue(char value) : value_(1, value) {
}

std::string StringValue::stringify() const {
  std::ostringstream oss;
  oss << '"' << value_ << '"';
  return oss.str();
}
} // namespace json
