#ifndef JSON_ARRAY_H_
#define JSON_ARRAY_H_

#include <initializer_list>
#include <string>
#include <vector>

#include "./base.h"

namespace json {
class ArrayValue : public ValueBase<ArrayValue> {
public:
  ArrayValue() = default;
  ArrayValue(const ArrayValue &) = default;
  ArrayValue(ArrayValue &&) = default;
  explicit ArrayValue(std::initializer_list<Value> value);
  ~ArrayValue() = default;
  ArrayValue &operator=(const ArrayValue &) = default;
  ArrayValue &operator=(ArrayValue &&) = default;

  std::string stringify() const;

private:
  std::vector<Value> value_;
}; // class ArrayValue
} // namespace json

#endif // JSON_ARRAY_H_
