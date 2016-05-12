#ifndef JSON_NUMBER_H_
#define JSON_NUMBER_H_

#include <string>

#include "./base.h"

namespace json {
class NumberValue : public ValueBase<NumberValue> {
public:
  NumberValue(double value);

  std::string stringify() const;

private:
  double value_;
}; // class NumberValue
} // namespace json

#endif // JSON_NUMBER_H_
