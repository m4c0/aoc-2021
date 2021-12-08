#include <fstream>
#include <iostream>

int main() {
  std::fstream in{"day2.txt"};
  int x = 0, y = 0, aim = 0;

  while (in) {
    std::string cmd;
    int delta;
    in >> cmd >> delta;
    if (!in)
      break;

    if (cmd == "forward") {
      x += delta;
      y += aim * delta;
    } else if (cmd == "up") {
      aim -= delta;
    } else if (cmd == "down") {
      aim += delta;
    }
  }

  std::cout << x << " " << y << " " << aim << " " << x * y << "\n";
  return 0;
}
