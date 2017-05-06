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
  int maximumGap(std::vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }
    std::list<std::bitset<32>> candidates;
    std::list<std::bitset<32>> zeros;
    std::list<std::bitset<32>> ones;
    for (int n : nums) {
      candidates.push_back(std::bitset<32>(n));
    }
    for (int i = 0; i < 32; ++i) {
      zeros.clear();
      ones.clear();
      for (auto& num : candidates) {
        if (num[i]) {
          ones.push_back(num);
        } else {
          zeros.push_back(num);
        }
      }
      candidates = zeros;
      candidates.insert(candidates.end(), ones.begin(), ones.end());
//      for (auto& c : candidates) {
//        std::cout << c.to_ulong() << " ";
//      }
//      std::cout << std::endl;
    }
    std::vector<int> numbers;
    for (auto& num : candidates) {
      numbers.push_back(num.to_ulong());
    }
    int maxGap = -1;
    for (size_t i = 1; i < numbers.size(); ++i) {
      if (numbers[i] - numbers[i - 1] > maxGap) {
        maxGap = numbers[i] - numbers[i - 1];
      }
    }
    return maxGap;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  std::vector<int> nums{3, 7, 4, 1};
  Solution s;
  std::cout << s.maximumGap(nums) << std::endl;

  return 0;
}