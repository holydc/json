#ifndef JSON_UTILS_H_
#define JSON_UTILS_H_

#include <string>
#include <type_traits>

namespace json {
namespace util {
template<class Type>
struct IsBoolean {
  static constexpr bool value = std::is_same<Type, bool>::value;
}; // struct IsBoolean

template<class Type>
struct IsNumber {
  static constexpr bool value = ((std::is_integral<Type>::value && !std::is_same<Type, bool>::value) || std::is_floating_point<Type>::value);
}; // struct IsNumber

template<class Type>
struct IsString {
  static constexpr bool value = (std::is_same<Type, char *>::value || std::is_same<Type, const char *>::value || std::is_same<Type, std::string>::value);
}; // struct IsString

template<class Type, bool = IsBoolean<Type>::value, bool = IsNumber<Type>::value, bool = IsString<Type>::value> struct ValueType;

template<class Type>
struct ValueType<Type, true, false, false> {
  typedef bool type;
}; // struct ValueType<true, false, false>

template<class Type>
struct ValueType<Type, false, true, false> {
  typedef double type;
}; // struct ValueType<false, true, false>

template<class Type>
struct ValueType<Type, false, false, true> {
  typedef std::string type;
}; // struct ValueType<false, false, true>
} // namespace util
} // namespace json

#endif // JSON_UTILS_H_
