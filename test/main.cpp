#include <iostream>

#include "../lib/json.h"

json::Value get() {
  return json::ArrayValue{{
    {"number", 5566},
    {"object",{
      {"boolean", true},
      {"array", json::ArrayValue{false, "1", 2}}
    }},
    {"string", "Hello, world!"}
  }};
}

int main() {
  json::Value foo = get();
  json::Value bar(foo);
  std::cout << bar.stringify() << std::endl;
  return 0;
}
