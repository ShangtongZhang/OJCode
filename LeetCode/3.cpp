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
  int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) { return 0; }
    std::unordered_set<char> info;
    int i = 0;
    int j = 0;
    int maxLen = -1;
    while (true) {
      while (i < s.size() && !info.count(s[i])) {
        info.insert(s[i]);
        i++;
      }
      maxLen = std::max(maxLen, i - j);
      if (i == s.size()) { break; }
      while (s[j] != s[i]) {
        info.erase(s[j]);
        j++;
      }
      j++;
      i++;
    }
    return maxLen;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::cout << s.lengthOfLongestSubstring("p");

  return 0;
}