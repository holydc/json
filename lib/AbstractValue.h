#ifndef JSON_ABSTRACTVALUE_H_
#define JSON_ABSTRACTVALUE_H_

#include <string>

#include "./include/Value.h"

namespace json {
class AbstractValue {
public:
  virtual ~AbstractValue() = default;

  virtual bool isArray() const = 0;
  virtual bool isBoolean() const = 0;
  virtual bool isNull() const = 0;
  virtual bool isNumber() const = 0;
  virtual bool isObject() const = 0;
  virtual bool isString() const = 0;

  virtual Value clone() const = 0;
  virtual std::string stringify() const = 0;
}; // class AbstractValue
} // namespace json

#endif // JSON_ABSTRACTVALUE_H_

