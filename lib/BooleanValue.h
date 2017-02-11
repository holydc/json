#ifndef JSON_BOOLEANVALUE_H_
#define JSON_BOOLEANVALUE_H_

#include "./BaseValue.h"

namespace json {
class BooleanValue : public BaseValue<BooleanValue> {
public:
  BooleanValue(bool value);

  std::string stringify() const override;

  inline bool value() const {
    return value_;
  }

private:
  bool value_;
}; // class BooleanValue
} // namespace json

#endif // JSON_BOOLEANVALUE_H_
