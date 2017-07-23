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
  int findLongestChain(std::vector<std::vector<int>>& pairs) {
    auto cmp = [](std::vector<int>& p1, std::vector<int>& p2) {
      return p1.front() < p2.front();
    };
    std::sort(pairs.begin(), pairs.end(), cmp);
    std::vector<int> D(pairs.size());
    D[0] = 1;
    for (int i = 1; i < pairs.size(); ++i) {
      D[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (pairs[j].back() < pairs[i].front()) {
          D[i] = std::max(D[i], D[j] + 1);
        }
      }
    }
    int res = 1;
    for (int i = 0; i < D.size(); ++i) {
      res = std::max(res, D[i]);
    }
    return res;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::vector<std::vector<int>> pairs{{1, 2}, {2, 3}, {3, 4}};
  std::cout << s.findLongestChain(pairs);

  return 0;
}