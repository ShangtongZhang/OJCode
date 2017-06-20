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
  class Node {
  public:
    int num;
    int minValue;
  };
  std::vector<Node> data;
  bool find132pattern(std::vector<int>& nums) {
    if (nums.size() < 3) { return false; }
    data.resize(nums.size());
    data.front().num = nums.front();
    data.front().minValue = std::numeric_limits<int>::max();
    for (int i = 1; i < data.size(); ++i) {
      data[i].num = nums[i];
      data[i].minValue = std::min(data[i - 1].minValue, nums[i - 1]);
    }
    return search(0, nums.size() - 1);
  }
  bool search(int l, int r) {
    if (r + 1 - l < 2) {
      return false;
    }
    int m = (l + r) / 2;
    if (search(l, m)) { return true; }
    if (search(m + 1, r)) { return true; }
    std::vector<Node> sorted;
    int pl = l;
    int pr = m + 1;
    std::vector<int> minValue(m + 1 - l);
    minValue.back() = data[m].minValue;
    for (int i = m - 1; i >= l; --i) {
      minValue[i - l] = std::min(minValue[i + 1 - l], data[i].minValue);
    }
    while (true) {
      if (data[pl].num <= data[pr].num) {
        sorted.push_back(data[pl++]);
      } else {
        if (data[pr].num > minValue[pl - l]) { return true; }
        sorted.push_back(data[pr++]);
      }
      if (pl > m) {
        while (pr <= r) { sorted.push_back(data[pr++]); }
        break;
      }
      if (pr > r) {
        while (pl <= m) { sorted.push_back(data[pl++]); }
        break;
      }
    }
    std::copy(sorted.begin(), sorted.end(), data.begin() + l);
    return false;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
//  std::vector<int> nums{1, 2, 3, 4};
  std::vector<int> nums{3, 1, 4, 2};
  std::cout << s.find132pattern(nums);

  return 0;
}