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
  std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
    if (nums.size() < 3) { return {}; }
    std::unordered_map<int, int> info;
    for (auto n : nums) {
      info[n] += 1;
    }
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) { continue; }
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) { continue; }
        int c = -nums[i] - nums[j];
        if (c >= nums[j] && info.count(c)) {
          if ((c != nums[i] && c != nums[j]) || (c == nums[i] && c == nums[j] && info[c] >= 3) ||
                  ((c == nums[i] && c != nums[j] || c == nums[j] && c != nums[i]) && info[c] >= 2)) {
            res.push_back({nums[i], nums[j], c});
          }
        }
      }
    }
    return res;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  auto res = s.threeSum({0, 0, 0, 0});
  std::cout << res.size();

  return 0;
}