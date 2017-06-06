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
  int findMin(std::vector<int> &nums) {
    return search(nums, 0, nums.size() - 1);
  }

  int search(std::vector<int>& nums, int l, int r) {
    if (l - r < 5) {
      std::sort(nums.begin() + l, nums.begin() + r + 1);
      return nums[l];
    }
    int m = (l + r) / 2;
    int min = nums[m + 1];
    if (nums[l] >= nums[m]) {
      min = std::min(m, search(nums, l, m));
    }
    if (nums[m + 1] >= nums[r]) {
      min = std::min(m, search(nums, m + 1, r));
    }
    return min;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  return 0;
}