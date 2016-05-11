#include "json.h"

#include <sstream>

namespace json {
// NumberValue
NumberValue::NumberValue(double value) : value_(value) {
}

std::string NumberValue::stringify() const {
  std::ostringstream oss;
  oss << value_;
  return oss.str();
}

// BooleanValue
BooleanValue::BooleanValue(bool value) : value_(value) {
}

std::string BooleanValue::stringify() const {
  return (value_ ? "true" : "false");
}

// StringValue
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

// ObjectValue
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

// ArrayValue
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

// Value
Value::Value(const Value &ref)
    : value_(std::move(ref.value_->make_value().value_)) {
}

Value::Value(NumberValue value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(std::move(value))) {
}

Value::Value(double value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(value)) {
}

Value::Value(int value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(unsigned int value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(long value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(unsigned long value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(long long value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(unsigned long long value)
    : value_(std::make_shared<ValueImpl<NumberValue>>(static_cast<double>(value))) {
}

Value::Value(BooleanValue value)
    : value_(std::make_shared<ValueImpl<BooleanValue>>(std::move(value))) {
}

Value::Value(bool value)
    : value_(std::make_shared<ValueImpl<BooleanValue>>(value)) {
}

Value::Value(StringValue value)
    : value_(std::make_shared<ValueImpl<StringValue>>(std::move(value))) {
}

Value::Value(std::string value)
    : value_(std::make_shared<ValueImpl<StringValue>>(std::move(value))) {
}

Value::Value(const char *value)
    : value_(std::make_shared<ValueImpl<StringValue>>(value)) {
}

Value::Value(char value)
    : value_(std::make_shared<ValueImpl<StringValue>>(value)) {
}

Value::Value(ObjectValue value)
    : value_(std::make_shared<ValueImpl<ObjectValue>>(std::move(value))) {
}

Value::Value(std::initializer_list<std::pair<const std::string, json::Value>> value)
    : value_(std::make_shared<ValueImpl<ObjectValue>>(std::move(value))) {
}

Value::Value(ArrayValue value)
    : value_(std::make_shared<ValueImpl<ArrayValue>>(std::move(value))) {
}

Value &Value::operator=(const Value &rhs) {
  return ((*this) = Value(rhs));
}

std::string Value::stringify() const {
  if (value_ == nullptr) {
    return "null";
  }
  return value_->stringify();
}
} // namespace json
