#include <fstream>
#include <iostream>

int main() {
  std::fstream in{"day1.txt"};
  int prev;
  in >> prev;

  int total = 0;
  while (in) {
    int current;
    in >> current;
    if (!in)
      break;
    if (prev < current) {
      total++;
    }
    prev = current;
  }
  std::cout << total << "\n";
  return 0;
}
