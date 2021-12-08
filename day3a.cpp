#include <fstream>
#include <iostream>
#include <map>

int main() {
  std::fstream in{"day3.txt"};
  std::map<int, int> counts{}; // pos -> count
  int total = 0;

  while (in) {
    std::string bin;
    in >> bin;
    if (!in)
      break;

    total++;
    for (int i = 0; i < bin.size(); i++) {
      if (bin[i] == '1') {
        counts[i]++;
      }
    }
  }

  int bit_size = 0;
  for (auto kv : counts) {
    bit_size = std::max(bit_size, kv.first);
  }

  int gamma = 0, epsilon = 0;
  for (auto kv : counts) {
    auto bit = bit_size - kv.first;
    if (kv.second > total - kv.second) {
      gamma |= 1 << bit;
    } else {
      epsilon |= 1 << bit;
    }
  }

  std::cout << gamma << " " << epsilon << " " << gamma * epsilon << "\n";

  return 0;
}
