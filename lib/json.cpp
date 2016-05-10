#include "json.h"

#include <sstream>

namespace json {
// Value
Value::Value(int value) : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(double value) : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(const char *value) : value_(std::make_shared<ValueImpl<StringValue>>(value)) {
}

Value::Value(std::string value) : value_(std::make_shared<ValueImpl<StringValue>>(std::move(value))) {
}

Value::Value(bool value) : value_(std::make_shared<ValueImpl<BooleanValue>>(value)) {
}

Value::Value(std::initializer_list<std::unordered_map<std::string, Value>::value_type> values) : value_(std::make_shared<ValueImpl<ObjectValue>>(std::move(values))) {
}

std::string Value::toString() const {
  return value_->toString();
}

// StringValue
StringValue::StringValue(const char *value) : value_(value) {
}

StringValue::StringValue(std::string value) : value_(std::move(value)) {
}

std::string StringValue::toString() const {
  std::ostringstream oss;
  oss << '"' << value_ << '"';
  return oss.str();
}

// NumberValue
NumberValue::NumberValue(double value) : value_(value) {
}

std::string NumberValue::toString() const {
  std::ostringstream oss;
  oss << value_;
  return oss.str();
}

// BooleanValue
BooleanValue::BooleanValue(bool value) : value_(value) {
}

std::string BooleanValue::toString() const {
  return (value_ ? "true" : "false");
}

// ObjectValue
ObjectValue::ObjectValue(std::initializer_list<std::unordered_map<std::string, Value>::value_type> values) : value_(values) {
}

std::string ObjectValue::toString() const {
  const char *separator = "";
  std::ostringstream oss;
  oss << '{';
  for (const auto &value : value_) {
    oss << separator << '"' << value.first << "\":" << value.second.toString();
    separator = ",";
  }
  oss << '}';
  return oss.str();
}
} // namespace json
