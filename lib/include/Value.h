#ifndef JSON_VALUE_H_
#define JSON_VALUE_H_

#include <initializer_list>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "./Utils.h"

namespace json {
class AbstractValue;

class Value {
public:
  static Value array(std::initializer_list<Value> value);
  static Value array(); //!< Create empty array value

  static Value object(std::initializer_list<std::pair<const std::string, Value>> value);
  static Value object(); //!< Create empty object value

  Value();
  Value(const Value &ref);
  Value &operator=(const Value &rhs);
  Value(Value &&) = default;
  Value &operator=(Value &&) = default;

  /**
   * Constructor for boolean, number, and string
   *
   * @param value Value of primitive types, including std::string
   */
  template<class Type>
  Value(Type value) {
    setValue(util::ValueType<Type>::type(std::move(value)));
  }

  /**
   * Constructor for array
   *
   * @param list Container of any list type (e.g. std::list, std::vector, std::set) with elements of type json::Value
   */
  template<template<class, class...> class List, class... Types>
  Value(List<Value, Types...> list) {
    std::vector<Value> value;
    for (auto &element : list) {
      value.emplace_back(std::move(element));
    }
    setValue(std::move(value));
  }

  /**
   * Constructor for object
   *
   * @param map Container of any map type (e.g. std::map) with keys of type std::string and values of type json::Value
   */
  template<template<class, class, class...> class Map, class... Types>
  Value(Map<std::string, Value, Types...> map) {
    std::unordered_map<std::string, Value> value;
    for (auto &entry : map) {
      value.emplace(std::move(entry.first), std::move(entry.second));
    }
    setValue(std::move(value));
  }

  /**
   * JavaScript-like object creation
   */
  Value(std::initializer_list<std::pair<const std::string, Value>> value);

  ~Value() = default;

  std::string stringify() const;

private:
  void setValue(std::vector<Value> value); //!< Set array value
  void setValue(bool value); //!< Set boolean value
  void setValue(double value); //!< Set number value
  void setValue(std::unordered_map<std::string, Value> value); //!< Set object value
  void setValue(std::string value); //!< Set string value

  std::shared_ptr<AbstractValue> value_;
}; // class Value
} // namespace json

#endif // JSON_VALUE_H_
