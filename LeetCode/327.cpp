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
  using int64 = long long int;
  int lower;
  int upper;
  int countRangeSum(std::vector<int> &nums, int lower, int upper) {
    if (nums.empty()) {
      return 0;
    }
    this->lower = lower;
    this->upper = upper;
    return count(nums, 0, nums.size());
  }

  bool isIn(int num) {
    return num >= lower && num <= upper;
  }

  int count(std::vector<int>& nums, int l, int r) {
    if (l + 1 == r) {
      return isIn(nums[l]);
    }
    int m = (l + r) / 2;
    std::vector<int64> prefix;
    for (int i = m - 1; i >= l; --i) {
      if (prefix.empty()) {
        prefix.push_back(nums[i]);
      } else {
        prefix.push_back(prefix.back() + nums[i]);
      }
    }
    std::sort(prefix.begin(), prefix.end());
    int64 suffix = 0;
    int nRanges = 0;
    for (int i = m; i < r; ++i) {
      suffix += nums[i];
      int64 newLower = lower - (int64)suffix;
      int64 newUpper = upper - (int64)suffix;
      auto itL = std::lower_bound(prefix.begin(), prefix.end(), newLower);
      auto itU = std::upper_bound(prefix.begin(), prefix.end(), newUpper);
      nRanges += itU - itL;
    }
    int nRangesL = count(nums, l, m);
    int nRangesR = count(nums, m, r);
    return nRanges + nRangesL + nRangesR;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  std::vector<int> nums{4,5,6};
  Solution s;
  std::cout << s.countRangeSum(nums, 5, 9) << std::endl;

  return 0;
}