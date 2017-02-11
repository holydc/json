#ifndef JSON_ARRAYVALUE_H_
#define JSON_ARRAYVALUE_H_

#include <vector>

#include "./BaseValue.h"

namespace json {
class ArrayValue : public BaseValue<ArrayValue> {
public:
  ArrayValue(std::vector<Value> value);

  std::string stringify() const override;

  inline const std::vector<Value> &value() const {
    return value_;
  }

private:
  std::vector<Value> value_;
}; // class ArrayValue
} // namespace json

#endif // JSON_ARRAYVALUE_H_
