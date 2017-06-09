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
  bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
    if (nums.size() <= 1 || k == 0 || t < 0) { return false; }
    std::map<long int, int> info;
    int i = 0;
    while (i < nums.size() && i <= k) { info[nums[i++]] += 1; }
    auto it = info.begin();
    auto next_it = std::next(it);
    while (true) {
      if (it->second > 1) { return true; }
      if (next_it == info.end()) { break; }
      if (next_it->first - it->first <= t) { return true; }
      it++;
      next_it++;
    }
    i = 0;
    while (true) {
      k++;
      if (k >= nums.size()) {
        break;
      }
      it = info.find(nums[i]);
      if (it->second > 1) {
        it->second -= 1;
      } else {
        info.erase(it);
      }
      info[nums[k]] += 1;
      it = info.find(nums[k]);
      if (it->second > 1) { return true; }
      if (it != info.begin()) {
        if (it->first - std::prev(it)->first<= t) { return true; }
      }
      next_it = std::next(it);
      if (next_it != info.end() && next_it->first - it->first <= t) { return true; }
      i++;
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
//  std::vector<int> nums{7, 2, 8};
//  int k = 2;
//  int t = 1;
  std::vector<int> nums{-1, -1};
  int k = 1;
  int t = 0;
  std::cout << s.containsNearbyAlmostDuplicate(nums, k, t);

  return 0;
}