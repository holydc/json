#ifndef JSON_STRING_H_
#define JSON_STRING_H_

#include <string>

#include "./base.h"

namespace json {
class StringValue : public ValueBase<StringValue> {
public:
  StringValue() = default;
  StringValue(const StringValue &) = default;
  StringValue(StringValue &&) = default;
  StringValue(std::string value);
  StringValue(const char *value);
  StringValue(char value);
  ~StringValue() = default;
  StringValue &operator=(const StringValue &) = default;
  StringValue &operator=(StringValue &&) = default;

  std::string stringify() const;

private:
  std::string value_;
}; // class StringValue
} // namespace json

#endif // JSON_STRING_H_
