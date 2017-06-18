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
  int maxDistance(std::vector<std::vector<int>>& arrays) {
    std::vector<int> minPos;
    int minValue = std::numeric_limits<int>::max();
    std::vector<int> maxPos;
    int maxValue = std::numeric_limits<int>::min();
    for (int i = 0; i < arrays.size(); ++i) {
      auto& arr = arrays[i];
      if (minValue > arr.front()) {
        minValue = arr.front();
        minPos.clear();
        minPos.push_back(i);
      } else if (minValue == arr.front()) {
        minPos.push_back(i);
      }
      if (maxValue < arr.back()) {
        maxValue = arr.back();
        maxPos.clear();
        maxPos.push_back(i);
      } else if (maxValue == arr.back()) {
        maxPos.push_back(i);
      }
    }
    if (minPos.size() > 1 || maxPos.size() > 1) {
      return std::abs(maxValue - minValue);
    }
    if (minPos[0] != maxPos[0]) {
      return std::abs(maxValue - minValue);
    }
    int newMinValue = std::numeric_limits<int>::max();
    for (int i = 0; i < arrays.size(); ++i) {
      if (i == maxPos[0]) { continue; }
      newMinValue = std::min(newMinValue, arrays[i].front());
    }
    int newMaxValue = std::numeric_limits<int>::min();
    for (int i = 0; i < arrays.size(); ++i) {
      if (i == minPos[0]) { continue; }
      newMaxValue = std::max(newMaxValue, arrays[i].back());
    }
    return std::max(std::abs(maxValue - newMinValue), std::abs(newMaxValue - minValue));
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  std::vector<std::vector<int>> arrays{{1,5}, {3,4}};
  Solution s;
  std::cout << s.maxDistance(arrays);

  return 0;
}