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
  int D[505][505];
  int minDistance(std::string word1, std::string word2) {
    if (word1.empty()) {
      return word2.size();
    }
    if (word2.empty()) {
      return word1.size();
    }
    std::memset(D, 0, sizeof(D));
    int l1 = word1.size();
    int l2 = word2.size();
    for (int i = 0; i < 505; ++i) {
      D[i][0] = D[0][i] = i;
    }
    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          D[i][j] = D[i - 1][j - 1];
        } else {
          D[i][j] = std::min(D[i - 1][j], D[i][j - 1]) + 1;
        }
      }
    }
    return D[l1][l2];
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.minDistance("ab", "a");

  return 0;
}