#include "./include/Value.h"

#include "./ArrayValue.h"
#include "./BooleanValue.h"
#include "./NullValue.h"
#include "./NumberValue.h"
#include "./ObjectValue.h"
#include "./StringValue.h"

namespace json {
Value Value::array(std::initializer_list<Value> value) {
  return Value(std::vector<Value>(std::move(value)));
}

Value Value::array() {
  return Value(std::vector<Value>());
}

Value Value::object(std::initializer_list<std::pair<const std::string, Value>> value) {
  return Value(std::move(value));
}

Value Value::object() {
  return Value(std::unordered_map<std::string, Value>());
}

Value::Value() : value_(std::make_shared<NullValue>()) {
}

Value::Value(const Value &ref) : value_(std::move(ref.value_->clone().value_)) {
}

Value &Value::operator=(const Value &rhs) {
  return ((*this) = Value(rhs));
}

Value::Value(std::initializer_list<std::pair<const std::string, Value>> value) {
  setValue(std::unordered_map<std::string, Value>(std::move(value)));
}

std::string Value::stringify() const {
  return value_->stringify();
}

void Value::setValue(std::vector<Value> value) {
  value_ = std::make_shared<ArrayValue>(std::move(value));
}

void Value::setValue(bool value) {
  value_ = std::make_shared<BooleanValue>(value);
}

void Value::setValue(double value) {
  value_ = std::make_shared<NumberValue>(value);
}

void Value::setValue(std::unordered_map<std::string, Value> value) {
  value_ = std::make_shared<ObjectValue>(std::move(value));
}

void Value::setValue(std::string value) {
  value_ = std::make_shared<StringValue>(std::move(value));
}
} // namespace json
