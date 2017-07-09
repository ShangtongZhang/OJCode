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
  int maximumProduct(std::vector<int> &nums) {
    std::vector<int> pos;
    std::vector<int> neg;
    bool zero = false;
    for (auto n : nums) {
      if (n > 0) { pos.push_back(n); }
      if (n < 0) { neg.push_back(-n); }
      if (n == 0) { zero = true; }
    }
    std::sort(pos.begin(), pos.end());
    std::sort(neg.begin(), neg.end());
    if (pos.empty()) {
      if (zero) { return 0; }
      return -neg[0] * neg[1] * neg[2];
    }
    if (pos.size() >= 3) {
      int i = pos.size() - 1;
      int c =  pos[i] * pos[i - 1] * pos[i - 2];
      if (neg.size() > 2) {
        i = neg.size() - 1;
        c = std::max(c, pos.back() * neg[i] * neg[i - 1]);
      }
      return c;
    }
    if (pos.size() == 1) {
      if (neg.size() <= 1) { return 0; }
      return pos.back() * neg.back() * neg[neg.size() - 2];
    }
    if (pos.size() == 2) {
      if (neg.empty()) { return 0; }
      if (neg.size() == 1) {
        if (zero) { return 0; }
        return pos[0] * pos[1] * neg[0];
      }
      if (neg.size() >= 2) {
        return pos.back() * neg.back() * neg[neg.size() - 2];
      }
    }
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::vector<int> nums{-1,-2,3, 4};
  std::cout << s.maximumProduct(nums);
  return 0;
}