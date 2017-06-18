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
  int smallestFactorization(int a) {
    if (a == 1) { return 1; }
    std::string res;
    if (!search(a, res)) { return 0; }
    std::reverse(res.begin(), res.end());
    long long int r = std::stoll(res);
    if (r > std::numeric_limits<int>::max()) {
      return false;
    }
    return r;
  }

  bool search(int a, std::string& res) {
    if (a == 1) { return true; }
    for (int i = 9; i > 1; --i) {
      if (a % i == 0) {
        res.push_back('0' + i);
        return search(a / i, res);
      }
    }
    return false;
  }

};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.smallestFactorization(17);

  return 0;
}