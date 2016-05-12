#ifndef JSON_OBJECT_H_
#define JSON_OBJECT_H_

#include <initializer_list>
#include <string>
#include <unordered_map>

#include "./base.h"

namespace json {
class ObjectValue : public ValueBase<ObjectValue> {
public:
  ObjectValue() = default;
  ObjectValue(const ObjectValue &) = default;
  ObjectValue(ObjectValue &&) = default;
  ObjectValue(std::initializer_list<std::pair<const std::string, json::Value>> value);
  ~ObjectValue() = default;
  ObjectValue &operator=(const ObjectValue &) = default;
  ObjectValue &operator=(ObjectValue &&) = default;

  std::string stringify() const;

private:
  std::unordered_map<std::string, Value> value_;
}; // class ObjectValue
} // namespace json

#endif // JSON_OBJECT_H_
