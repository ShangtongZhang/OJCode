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
  bool checkSubarraySum(std::vector<int>& nums, int k) {
    if (nums.size() < 2) { return false; }
    k = std::abs(k);
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (!nums[i] && !nums[i + 1]) { return true; }
    }
    if (k == 0) {
      return false;
    }
    std::unordered_set<int> info;
    int r = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int n = nums[i];
      if (n % k == 0) {
        if (i > 1 && nums[i - 1] % k == 0) { return true; }
        if (i < nums.size() - 1 && nums[i + 1] % k == 0) { return true; }
      }
      r += n;
      r %= k;
      if (!r) {
        if (n % k == 0) { continue; }
        return true;
      }
      if (info.count(r)) { return true; }
      info.insert(r);
    }
    return false;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
//  Solution s;
//  std::cout << s.checkSubarraySum({0, 1, 0}, -1);

  return 0;
}