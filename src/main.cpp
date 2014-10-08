#include <iostream>

using namespace std;

#include <json11/json11.hpp>

using json11::Json;

int main(int argc, char *argv[]) {
  Json json = Json::object {
    { "hello", "world" },
    { "welcome", "you" },
  };

  cout << json.dump() << endl;
}
