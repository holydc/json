#ifndef JSON_NUMBERVALUE_H_
#define JSON_NUMBERVALUE_H_

#include "./BaseValue.h"

namespace json {
class NumberValue : public BaseValue<NumberValue> {
public:
  NumberValue(double value);

  std::string stringify() const override;

  inline double value() const {
    return value_;
  }

private:
  double value_;
}; // class NumberValue
} // namespace json

#endif // JSON_NUMBERVALUE_H_
