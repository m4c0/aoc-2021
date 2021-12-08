#include <fstream>
#include <iostream>

int main() {
  std::fstream in{"day2.txt"};
  int x = 0, y = 0;

  while (in) {
    std::string cmd;
    int delta;
    in >> cmd >> delta;
    if (!in)
      break;

    if (cmd == "forward") {
      x += delta;
    } else if (cmd == "up") {
      y -= delta;
    } else if (cmd == "down") {
      y += delta;
    }
  }

  std::cout << x << " " << y << " " << x * y << "\n";
  return 0;
}
