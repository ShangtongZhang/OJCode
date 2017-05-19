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
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> map;
    for (auto c : t) {
      map[c]++;
    }
    int l = 0;
    int r = 0;
    int count = t.size();
    int minLen = std::numeric_limits<int>::max();
    int bestL = -1;
    while (r < s.size()) {
      if (!map.count(s[r])) {
        r++;
        continue;
      }
      if(map[s[r]]-- > 0) {
        count--;
      }
      r++;
      while (count == 0) {
        if (r - l < minLen) {
          minLen = r - l;
          bestL = l;
        }
        if (!map.count(s[l])) {
          l++;
          continue;
        }
        if (map[s[l]]++ >= 0) {
          count++;
        }
        l++;
      }
    }
    if (bestL > -1) {
      return s.substr(bestL, minLen);
    }
    return "";
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.minWindow("ADOBECODEBANC", "ABC");
  return 0;
}