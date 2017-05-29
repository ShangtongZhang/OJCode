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
  std::vector<int> D;
  int countDigitOne(int n) {
    if (n <= 0) {
      return 0;
    }
    D.resize(14);
    D[1] = 1;
    int pow = 10;
    for (int i = 2; i < 14; ++i) {
      D[i] = D[i - 1] * 10 + pow;
      pow *= 10;
    }
    std::vector<int> digits;
    while (n) {
      digits.insert(digits.begin(), n % 10);
      n /= 10;
    }
    return search(digits, 0);
  }

  int search(std::vector<int>& digits, int pos) {
    if (pos == digits.size() - 1) {
      if (digits[pos] > 0) {
        return 1;
      }
      return 0;
    }
    if (digits[pos] == 0) {
      return search(digits, pos + 1);
    }
    int rDigits = digits.size() - pos - 1;
    int res = digits[pos]* D[rDigits];
    if (digits[pos] > 1) {
      res += (int)std::pow(10, rDigits);
    } else if (digits[pos] == 1) {
      int n = 0;
      for (int i = pos + 1; i < digits.size() ; ++i) {
        n *= 10;
        n += digits[i];
      }
      res += n + 1;
    }
    int c = search(digits, pos + 1);
    return res + c;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.countDigitOne(101);

  return 0;
}