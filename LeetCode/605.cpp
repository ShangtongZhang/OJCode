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
  bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
    int i = 0;
    while (n) {
      if (i == flowerbed.size()) {
        break;
      }
      if (flowerbed[i]) {
        i++;
        continue;
      }
      if ((i - 1 < 0 || !flowerbed[i - 1]) && (i + 1 >= flowerbed.size() || !flowerbed[i + 1])) {
        n--;
        flowerbed[i] = 1;
        i++;
        continue;
      }
      i++;
    }
    return !n;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> nums{1,0,0,0,1,0,0};
  std::cout << s.canPlaceFlowers(nums, 2);

  return 0;
}