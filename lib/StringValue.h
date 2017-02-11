#ifndef JSON_STRINGVALUE_H_
#define JSON_STRINGVALUE_H_

#include <string>

#include "./BaseValue.h"

namespace json {
class StringValue : public BaseValue<StringValue> {
public:
  StringValue(std::string value);

  std::string stringify() const override;

  inline const std::string &value() const {
    return value_;
  }

private:
  std::string value_;
}; // class StringValue
} // namespace json

#endif // JSON_STRINGVALUE_H_
