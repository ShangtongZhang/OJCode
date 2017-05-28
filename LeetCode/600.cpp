#include "iostream"
#include "vector"
#include "map"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "sstream"
#include "queue"
#include "fstream"
#include "iomanip"
#include "cstring"
#include "bitset"
#include "unordered_map"
#include "unordered_set"
#include "numeric"
#include "cmath"

class Solution {
public:
  int findIntegers(int num) {
    if (num == 0) {
      return 0;
    }
    int D[32][2];
    D[0][0] = 1;
    D[0][1] = 1;
    for (int i = 1; i < 32; ++i) {
      D[i][0] = D[i - 1][0] + D[i - 1][1];
      D[i][1] = D[i - 1][0];
    }
    std::bitset<32> n(num);
    bool T[32];
    T[31] = false;
    for (int i = 30; i >= 0; --i) {
      if (T[i + 1]) {
        T[i] = true;
      } else {
        T[i] = n[i] && n[i + 1];
      }
    }
    int i = 31;
    while (!n[i]) { i--; }
    int count = D[i][1] + D[i][0];
    while (i >= 0) {
      if (!n[i] && !n[i + 1] && !T[i]) {
        count -= D[i][1];
      }
      i--;
    }
    return count;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::cout << s.findIntegers(12);

  return 0;
}