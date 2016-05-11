#ifndef JSON_LIB_JSON_H_
#define JSON_LIB_JSON_H_

#include <initializer_list>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

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

private:
  struct IValue {
    virtual ~IValue() = default;

    virtual std::string stringify() const = 0;
    virtual Value make_value() const = 0;
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

    ValueType value_;
  }; // struct ValueImpl

  std::shared_ptr<IValue> value_;
}; // class Value

template<class ValueType>
struct ValueBase {
  virtual ~ValueBase() = default;

  Value make_value() const {
    return Value(*(static_cast<const ValueType *>(this)));
  }
}; // struct ValueBase

class NumberValue : public ValueBase<NumberValue> {
public:
  NumberValue(double value);

  std::string stringify() const;

private:
  double value_;
}; // class NumberValue

class BooleanValue : public ValueBase<BooleanValue> {
public:
  BooleanValue(bool value);

  std::string stringify() const;

private:
  bool value_;
}; // class BooleanValue

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

class ArrayValue : public ValueBase<ArrayValue> {
public:
  ArrayValue() = default;
  ArrayValue(const ArrayValue &) = default;
  ArrayValue(ArrayValue &&) = default;
  explicit ArrayValue(std::initializer_list<Value> value);
  ~ArrayValue() = default;
  ArrayValue &operator=(const ArrayValue &) = default;
  ArrayValue &operator=(ArrayValue &&) = default;

  std::string stringify() const;

private:
  std::vector<Value> value_;
}; // class ArrayValue
} // namespace json

#endif // JSON_LIB_JSON_H_
