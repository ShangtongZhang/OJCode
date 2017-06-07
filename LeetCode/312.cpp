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
  std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, int>>>> D;
  int maxCoins(std::vector<int>& nums) {
    return search(nums, 0, nums.size() - 1, 1, 1);
  }
  int search(std::vector<int>& nums, int i, int j, int l, int r) {
    if (i > j) {
      return 0;
    }
    if (D[i][j][l][r]) {
      return D[i][j][l][r];
    }
    int max = 0;
    for (int k = i; k <= j; ++k) {
      max = std::max(max,
                     search(nums, i, k - 1, l, nums[k]) +
                             search(nums, k + 1, j, nums[k], r) + l * nums[k] * r);
    }
    D[i][j][l][r] = max;
    return max;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> nums{3, 1, 5, 8};
  std::cout << s.maxCoins(nums);

  return 0;
}