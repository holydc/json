#include <iostream>

#include "../lib/include/json.h"

int main() {
  json::Value json = {
    {"description", "A simple JSON library in C++"},
    {"version", 0.001},
    {"free", true},
    {"author", json::Value::array({
      {
        {"name", "holydc"},
        {"email", "holydc@gmail.com"}
      },
      "And you :)"
    })}
  };
  std::cout << json.stringify() << std::endl;
  return 0;
}
