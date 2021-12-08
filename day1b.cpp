#include <fstream>
#include <iostream>

int main() {
  std::fstream in{"day1.txt"};
  int a, b, c;
  in >> a >> b >> c;

  int total = 0;
  while (in) {
    int d;
    in >> d;
    if (!in)
      break;
    if (a + b + c < b + c + d) {
      total++;
    }
    a = b;
    b = c;
    c = d;
  }
  std::cout << total << "\n";
  return 0;
}
