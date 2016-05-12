#include "./value.h"

#include "./array.h"
#include "./boolean.h"
#include "./number.h"
#include "./object.h"
#include "./string.h"

namespace json {
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

bool Value::isNumber() const {
  return value_->isNumber();
}

bool Value::isBoolean() const {
  return value_->isBoolean();
}

bool Value::isString() const {
  return value_->isString();
}

bool Value::isObject() const {
  return value_->isObject();
}

bool Value::isArray() const {
  return value_->isArray();
}

Value make_array(std::initializer_list<Value> value) {
  return ArrayValue(std::move(value));
}
} // namespace json
