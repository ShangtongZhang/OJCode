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
  int findUnsortedSubarray(std::vector<int> &nums) {
    std::vector<int> count(nums.size(), 0);
    int maxValue = nums[0];
    int pos = -1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] >= maxValue) {
        count[i] = count[i - 1];
        maxValue = nums[i];
      } else {
        for (int j = 0; j < i; ++j) {
          if (nums[j] > nums[i]) {
            count[i] = count[j] + i - j + 1;
            if (pos > -1) {
              count[i] = std::max(count[i], count[pos] + i - pos);
            }
            pos = i;
            break;
          }
        }
      }
    }
    return count.back();
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

//  std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  std::vector<int> nums = {1, 3, 5, 4, 2};
//  std::vector<int> nums = {1,2,3,5,4};
  Solution s;
  std::cout << s.findUnsortedSubarray(nums) << std::endl;

  return 0;
}