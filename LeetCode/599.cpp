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
  std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2) {
    std::unordered_map<std::string, int> l1;
    for (int i = 0; i < list1.size(); ++i) {
      l1[list1[i]] = i;
    }
    std::unordered_map<std::string, int> l2;
    for (int i = 0; i < list2.size(); ++i) {
      l2[list2[i]] = i;
    }
    int minSum = std::numeric_limits<int>::max();
    std::vector<std::string> res;
    for (auto it = l1.begin(); it != l1.end(); ++it) {
      auto it2 = l2.find(it->first);
      if (it2 != l2.end()) {
        int curSum = it->second + it2->second;
        if (curSum < minSum) {
          res.clear();
          minSum = curSum;
          res.push_back(it->first);
        } else if (curSum == minSum) {
          res.push_back(it->first);
        }
      }
    }
    return res;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}