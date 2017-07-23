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
  std::vector<int> findErrorNums(std::vector<int>& nums) {
    std::vector<bool> info(10005);
    for (int i = 0; i < info.size(); ++i) {
      info[i] = false;
    }
    std::vector<int> res;
    for (auto num : nums) {
      if (!info[num]) {
        info[num] = true;
      } else {
        res.push_back(num);
      }
    }
    for (int i = 1; i < info.size(); ++i) {
      if (!info[i]) {
        res.push_back(i);
        break;
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
  std::vector<int> nums{1, 2, 2, 4};
  s.findErrorNums(nums);

  return 0;
}