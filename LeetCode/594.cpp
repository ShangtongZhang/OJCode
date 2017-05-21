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
  int findLHS(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    std::map<int, int> count;
    if (count.size() == 1) {
      return 0;
    }
    for (auto num : nums) {
      count[num] += 1;
    }
    int maxLen = 0;
    for (auto it = count.begin(); it != std::prev(count.end()); ++it) {
      auto next = std::next(it);
      if (next->first > it->first + 1) {
        continue;
      }
      maxLen = std::max(maxLen, it->second + next->second);
    }
    return maxLen;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> nums{1,3,2,2,5,2,3,7};
  std::cout << s.findLHS(nums);

  return 0;
}