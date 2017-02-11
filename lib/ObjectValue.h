#ifndef JSON_OBJECTVALUE_H_
#define JSON_OBJECTVALUE_H_

#include <string>
#include <unordered_map>

#include "./BaseValue.h"

namespace json {
class ObjectValue : public BaseValue<ObjectValue> {
public:
  ObjectValue(std::unordered_map<std::string, Value> value);

  std::string stringify() const override;

  inline const std::unordered_map<std::string, Value> &value() const {
    return value_;
  }

private:
  std::unordered_map<std::string, Value> value_;
}; // class ObjectValue
} // namespace json

#endif // JSON_OBJECTVALUE_H_
