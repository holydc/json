#ifndef JSON_BASEVALUE_H_
#define JSON_BASEVALUE_H_

#include <type_traits>

#include "./AbstractValue.h"

namespace json {
class ArrayValue;
class BooleanValue;
class NullValue;
class NumberValue;
class ObjectValue;
class StringValue;

template<class ConcreteValue>
class BaseValue : public AbstractValue {
public:
  bool isArray() const override {
    return std::is_same<ConcreteValue, ArrayValue>::value;
  }

  bool isBoolean() const override {
    return std::is_same<ConcreteValue, BooleanValue>::value;
  }

  bool isNull() const override {
    return std::is_same<ConcreteValue, NullValue>::value;
  }

  bool isNumber() const override {
    return std::is_same<ConcreteValue, NumberValue>::value;
  }

  bool isObject() const override {
    return std::is_same<ConcreteValue, ObjectValue>::value;
  }

  bool isString() const override {
    return std::is_same<ConcreteValue, StringValue>::value;
  }

  Value clone() const override {
    return Value(static_cast<const ConcreteValue *>(this)->value());
  }
}; // class BaseValue
} // namespace json

#endif // JSON_BASEVALUE_H_

