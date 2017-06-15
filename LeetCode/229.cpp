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
  bool ok(std::vector<int> &nums, int i) {
    int threshold = nums.size() / 3;
    int count = 0;
    for (auto& num : nums) {
      count += num == i;
    }
    return count > threshold;
  }
  std::vector<int> majorityElement(std::vector<int> &nums) {
    std::vector<std::pair<int, int>> info(3);
    auto cmp = [](std::pair<int, int>& p1, std::pair<int, int>&p2) {
      return p1.second < p2.second;
    };
    for (auto n : nums) {
      std::sort(info.begin(), info.end(), cmp);
      bool flag = true;
      for (auto& node : info) {
        if (node.first == n) {
          node.second += 1;
          flag = false;
          break;
        }
      }
      if (flag) {
        int i = 0;
        while (i < 3) {
          if (info[i].second == 0) {
            info[i].first = n;
            info[i].second = 1;
            break;
          }
          i++;
        }
        if (i == 3) {
          info[0].second -= 1;
        }
      }
    }
    std::vector<int> res;
    for (auto& p : info) {
      if (ok(nums, p.first)) { res.push_back(p.first); }
    }
    return std::vector<int>(res.begin(), std::unique(res.begin(), res.end()));
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> nums{0, 0, 0};
  auto res = s.majorityElement(nums);
  for (auto n: res) { std::cout << n << " "; }
  return 0;
}