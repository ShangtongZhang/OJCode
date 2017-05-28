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
  int arrayNesting(std::vector<int>& nums) {
    std::vector<bool> flag(nums.size());
    int max = -1;
    for (int i = 0; i < nums.size(); ++i) {
      int j = i;
      int size = 0;
      while (!flag[j]) {
        size++;
        flag[j] = true;
        j = nums[j];
      }
      max = std::max(size, max);
    }
    return max;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::vector<int> nums{5,4,0,3,1,6,2};
  std::cout << s.arrayNesting(nums);

  return 0;
}