#ifndef JSON_BASE_H_
#define JSON_BASE_H_

#include <type_traits>

#include "./value.h"

namespace json {
template<class ValueType>
struct ValueBase {
  virtual ~ValueBase() = default;

  Value make_value() const {
    return Value(*(static_cast<const ValueType *>(this)));
  }

  bool isNumber() const {
    return std::is_same<ValueType, NumberValue>::value;
  }

  bool isBoolean() const {
    return std::is_same<ValueType, BooleanValue>::value;
  }

  bool isString() const {
    return std::is_same<ValueType, StringValue>::value;
  }

  bool isObject() const {
    return std::is_same<ValueType, ObjectValue>::value;
  }

  bool isArray() const {
    return std::is_same<ValueType, ArrayValue>::value;
  }
}; // struct ValueBase
} // namespace json

#endif // JSON_BASE_H_
