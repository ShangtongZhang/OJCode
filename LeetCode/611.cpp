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
  int triangleNumber(std::vector<int>& nums) {
    if (nums.size() < 3) { return 0; }
    std::sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        auto it = nums.begin() + j + 1;
        auto r_it = std::lower_bound(it, nums.end(), nums[i] + nums[j]);
        auto l_it = std::upper_bound(it, nums.end(), std::abs(nums[i] - nums[j]));
        if (r_it > l_it) { count += r_it - l_it; }
      }
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
  std::vector<int> nums{2,2,3,4};
  std::cout << s.triangleNumber(nums);

  return 0;
}