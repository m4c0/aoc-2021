#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

int rating(std::vector<std::string> lines, auto cmp) {
  int i = 0;
  while (lines.size() > 1) {
    std::vector<std::string> zeroes{};
    std::vector<std::string> ones{};
    for (std::string line : lines) {
      if (line[i] == '1') {
        ones.push_back(line);
      } else {
        zeroes.push_back(line);
      }
    }
    if (cmp(zeroes.size(), ones.size())) {
      lines = zeroes;
    } else {
      lines = ones;
    }
    std::cout << zeroes.size() << " " << ones.size() << " " << lines.at(0).at(i)
              << "\n";
    i++;
  }

  int res = 0;
  for (auto c : lines[0]) {
    res <<= 1;
    if (c == '1') {
      res |= 1;
    }
  }
  return res;
}

int main() {
  std::fstream in{"day3.txt"};
  std::vector<std::string> lines{};

  while (in) {
    std::string bin;
    in >> bin;
    if (!in)
      break;

    lines.push_back(bin);
  }

  int oxy = rating(lines, std::greater<int>());
  int co2 = rating(lines, std::less_equal<int>());

  std::cout << oxy << " " << co2 << " " << oxy * co2 << "\n";

  return 0;
}
