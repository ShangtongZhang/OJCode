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
  std::string removeDuplicateLetters(std::string s) {
    std::string prefix;
    while (true) {
      std::string res = remove(s, prefix);
      if (res.empty()) {
        break;
      }
      s = res;
    }
    return prefix;
  }

  std::string remove(std::string& s, std::string& prefix) {
    for (char c = 'a'; c <= 'z'; ++c) {
      if (tryRemove(s, c)) {
        size_t pos = s.find(c);
        prefix.push_back(c);
        std::string res;
        for (size_t i = pos + 1; i < s.size(); ++i) {
          if (s[i] != c) {
            res.push_back(s[i]);
          }
        }
        return res;
      }
    }
    return s;
  }

  bool tryRemove(const std::string& s, char cur) {
    size_t pos = s.find(cur);
    if (pos == std::string::npos) {
      return false;
    }
    for (size_t i = 0; i < pos; ++i) {
      if (s.find_last_of(s[i]) < pos) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::string line;
  while (std::cin >> line) {
    std::cout << s.removeDuplicateLetters(line) << std::endl;
  }

  return 0;
}