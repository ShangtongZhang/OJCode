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
  int countSubstrings(std::string s) {
    if (s.empty()) { return 0; }
    if (s.size() == 1) { return 1; }
    std::vector<std::vector<bool>> D(s.size());
    for (auto &row : D) {
      row.resize(s.size());
    }
    for (int l = 0; l < s.size(); ++l) {
      for (int i = 0; i < s.size(); ++i) {
        int j = i + l;
        if (j >= s.size()) {
          break;
        }
        if (j == i) {
          D[i][j] = true;
        } else if (j == i + 1) {
          D[i][j] = s[i] == s[j];
        } else {
          if (s[i] == s[j]) {
            D[i][j] = D[i + 1][j - 1];
          } else {
            D[i][j] = false;
          }
        }
      }
    }
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i; j < s.size(); ++j) {
        count += D[i][j];
      }
    }
    return count;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::cout << s.countSubstrings("abc");

  return 0;
}