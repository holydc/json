#ifndef JSON_VALUE_H_
#define JSON_VALUE_H_

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>

namespace json {
class NumberValue;
class BooleanValue;
class StringValue;
class ObjectValue;
class ArrayValue;

class Value {
public:
  Value() = default;
  Value(const Value &ref);
  Value(Value &&) = default;

  // number
  Value(NumberValue value);
  Value(double value);
  Value(int value);
  Value(unsigned int value);
  Value(long value);
  Value(unsigned long value);
  Value(long long value);
  Value(unsigned long long value);

  // boolean
  Value(BooleanValue value);
  Value(bool value);

  // string
  Value(StringValue value);
  Value(std::string value);
  Value(const char *value);
  Value(char value);

  // object
  Value(ObjectValue value);
  Value(std::initializer_list<std::pair<const std::string, json::Value>> value);

  // array
  Value(ArrayValue value);

  ~Value() = default;
  Value &operator=(const Value &rhs);
  Value &operator=(Value &&) = default;

  std::string stringify() const;

  bool isNumber() const;
  bool isBoolean() const;
  bool isString() const;
  bool isObject() const;
  bool isArray() const;

private:
  struct IValue {
    virtual ~IValue() = default;

    virtual std::string stringify() const = 0;
    virtual Value make_value() const = 0;
    virtual bool isNumber() const = 0;
    virtual bool isBoolean() const = 0;
    virtual bool isString() const = 0;
    virtual bool isObject() const = 0;
    virtual bool isArray() const = 0;
  }; // struct IValue

  template<class ValueType>
  struct ValueImpl : public IValue {
    ValueImpl(ValueType value) : value_(std::move(value)) {
    }

    std::string stringify() const override {
      return value_.stringify();
    }

    Value make_value() const override {
      return value_.make_value();
    }

    bool isNumber() const override {
      return value_.isNumber();
    }

    bool isBoolean() const override {
      return value_.isBoolean();
    }

    bool isString() const override {
      return value_.isString();
    }

    bool isObject() const override {
      return value_.isObject();
    }

    bool isArray() const override {
      return value_.isArray();
    }

    ValueType value_;
  }; // struct ValueImpl

  std::shared_ptr<IValue> value_;
}; // class Value

Value make_array(std::initializer_list<Value> value);
} // namespace json

template<class Char, class Traits>
std::basic_ostream<Char, Traits> &operator<<(std::basic_ostream<Char, Traits> &lhs, const json::Value &rhs) {
  return (lhs << rhs.stringify());
}

#endif // JSON_VALUE_H_
