#ifndef JSON_LIB_JSON_H_
#define JSON_LIB_JSON_H_

#include <initializer_list>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace json {
class Value {
public:
  Value() = default;
  Value(int value);
  Value(double value);
  Value(const char *value);
  Value(std::string value);
  Value(bool value);
  Value(std::initializer_list<std::unordered_map<std::string, Value>::value_type> values);

  std::string toString() const;

private:
  struct IValue {
    virtual ~IValue() = default;

    virtual std::string toString() const = 0;
  }; // struct IValue

  template<class ValueType>
  struct ValueImpl : public IValue {
    ValueImpl(ValueType value) : value_(std::move(value)) {
    }

    std::string toString() const override {
      return value_.toString();
    }

    ValueType value_;
  }; // struct ValueImpl

  std::shared_ptr<IValue> value_;
}; // class Value

class StringValue {
public:
  StringValue(const char *value);
  StringValue(std::string value);

  std::string toString() const;

private:
  std::string value_;
}; // class StringValue

class NumberValue {
public:
  NumberValue(double value);

  std::string toString() const;

private:
  double value_;
}; // class NumberValue

class BooleanValue {
public:
  BooleanValue(bool value);

  std::string toString() const;

private:
  bool value_;
}; // class BooleanValue

class ObjectValue {
public:
  ObjectValue(std::initializer_list<std::unordered_map<std::string, Value>::value_type> values);

  std::string toString() const;

private:
  std::unordered_map<std::string, Value> value_;
}; // class ObjectValue

class ArrayValue {
public:
private:
  std::vector<Value> value_;
}; // class ArrayValue
} // namespace json

#endif // JSON_LIB_JSON_H_
