#include <iostream>

#include "../lib/json.h"

int main() {
  json::Value val{
    { "foo", 5566 },
    { "bar", {
      { "a", "orz" },
      { "b", "XD" }
    } },
    { "baz", false }
  };
  std::cout << val.toString() << std::endl;
  return 0;
}
