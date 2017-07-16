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
  double findMaxAverage(std::vector<int> &nums, int k) {
    int i = 0;
    double sum = 0;
    while (i < k) {
      sum += nums[i];
      i++;
    }
    double maxSum = sum;
    for (i = k; i < nums.size(); ++i) {
      sum -= nums[i - k];
      sum += nums[i];
      maxSum = std::max(sum, maxSum);
    }
    return maxSum / k;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::vector<int> nums{1,12,-5,-6,50,3};
  std::cout << s.findMaxAverage(nums, 4);

  return 0;
}