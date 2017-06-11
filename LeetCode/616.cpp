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
  std::string addBoldTag(std::string s, std::vector<std::string> &dict) {
    std::vector<bool> flag(s.size());
    for (auto& str : dict) {
      int pos = s.find(str);
      while (pos != std::string::npos) {
        for (int i = 0; i < str.size(); ++i) {
          flag[pos + i] = true;
        }
        pos = s.find(str, pos + 1);
      }
    }
    std::string res;
    int i = 0;
    int last = 0;
    while (true) {
      while (i < flag.size() && !flag[i]) {
        res.push_back(s[i]);
        i++;
      }
      if (i == flag.size()) { break; }
      res += "<b>";
      while (i < flag.size() && flag[i]) {
        res.push_back(s[i]);
        i++;
      }
      res += "</b>";
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
//  std::vector<std::string> dict{"aaa","aab","bc"};
  std::vector<std::string> dict{"a","b","c"};
  std::cout << s.addBoldTag("aaabbcc", dict);

  return 0;
}