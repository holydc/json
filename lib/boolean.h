#ifndef JSON_BOOLEAN_H_
#define JSON_BOOLEAN_H_

#include <string>

#include "./base.h"

namespace json {
class BooleanValue : public ValueBase<BooleanValue> {
public:
  BooleanValue(bool value);

  std::string stringify() const;

private:
  bool value_;
}; // class BooleanValue
} // namespace json

#endif // JSON_BOOLEAN_H_
