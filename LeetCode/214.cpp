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

class SolutionTLE {
public:
  std::string shortestPalindrome(std::string s) {
    std::vector<std::vector<int>> D(s.size());
    for (auto& row : D) {
      row.resize(s.size());
    }
    for (int i = 0; i < s.size(); ++i) {
      D[i][i] = 1;
    }
    for (int l = 1; l < s.size(); ++l) {
      for (int i = 0; i < s.size(); ++i) {
        int j = i + l;
        if (j >= s.size()) {
          break;
        }
        if (s[i] == s[j]) {
          D[i][j] = l == 1 ? 1 : D[i + 1][j - 1];
        } else {
          D[i][j] = 0;
        }
      }
    }
    int i;
    for (i = s.size() - 1; i >= 0; --i) {
      if (D[0][i]) {
        break;
      }
    }
    std::string res;
    for (int j = s.size() - 1; j > i; --j) {
      res.push_back(s[j]);
    }
    res += s;
    return res;
  }
};

class Solution {
public:
  std::string shortestPalindrome(std::string s) {
    std::string rs = s;
    std::reverse(rs.begin(), rs.end());
    std::string tmp = s + '#' + rs;
    int l = KMPTable(tmp);
    rs = s.substr(l);
    std::reverse(rs.begin(), rs.end());
    return rs + s;
  }

  int KMPTable(std::string& s) {
    std::vector<int> table(s.size());
    table[0] = 0;
    int pos = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[pos]) {
        table[i] = table[i - 1] + 1;
        pos++;
      } else {
        pos = table[i - 1];
        while (pos > 0 && s[pos] != s[i]) {
          pos = table[pos - 1];
        }
        if (pos == 0) {
          table[i] = s[pos] == s[i];
        } else {
          table[i] = pos + 1;
          pos++;
        }
      }
    }
    return table.back();
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.shortestPalindrome("abcd");
  return 0;
}