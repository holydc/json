#include <iostream>

#include "../lib/value.h"

json::Value get() {
  return {
    { "number", 5566 },
    { "object", {
      { "boolean", true },
      { "array", json::make_array({ false, "1", 2 }) }
    } },
    { "string", "Hello, world!" }
  };
}

int main() {
  json::Value foo = get();
  json::Value bar(foo);
  std::cout << bar << std::endl;
  std::cout << "isArray:" << std::boolalpha << bar.isArray() << std::endl;
  std::cout << "isBoolean:" << std::boolalpha << bar.isBoolean() << std::endl;
  std::cout << "isNumber:" << std::boolalpha << bar.isNumber() << std::endl;
  std::cout << "isObject:" << std::boolalpha << bar.isObject() << std::endl;
  std::cout << "isString:" << std::boolalpha << bar.isString() << std::endl;
  return 0;
}
