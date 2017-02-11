#include "./NullValue.h"

namespace json {
bool NullValue::isArray() const {
  return false;
}

bool NullValue::isBoolean() const {
  return false;
}

bool NullValue::isNull() const {
  return true;
}

bool NullValue::isNumber() const {
  return false;
}

bool NullValue::isObject() const {
  return false;
}

bool NullValue::isString() const {
  return false;
}

Value NullValue::clone() const {
  return Value();
}

std::string NullValue::stringify() const {
  return "null";
}
} // namespace json
