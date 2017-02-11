#ifndef JSON_NULLVALUE_H_
#define JSON_NULLVALUE_H_

#include "./AbstractValue.h"

namespace json {
class NullValue : public AbstractValue {
public:
  bool isArray() const override;
  bool isBoolean() const override;
  bool isNull() const override;
  bool isNumber() const override;
  bool isObject() const override;
  bool isString() const override;

  Value clone() const override;
  std::string stringify() const override;
}; // class NullValue
} // namespace json

#endif // JSON_NULLVALUE_H_

