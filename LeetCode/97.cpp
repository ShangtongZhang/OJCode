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
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    return search(s1, s2, s3, 0, 0, 0);
  }

  bool search(std::string& s1, std::string& s2, std::string& s3, int p1, int p2, int p3) {
    if (p1 == s1.size() && p2 == s2.size() && p3 == s3.size()) {
      return true;
    }
    if (p1 < s1.size() && p3 < s3.size() && s3[p3] == s1[p1]) {
      if(search(s1, s2, s3, p1 + 1, p2, p3 + 1)) {
        return true;
      }
    }
    if (p2 < s2.size() && p3 < s3.size() && s3[p3] == s2[p2]) {
      return search(s1, s2, s3, p1, p2 + 1, p3 + 1);
    }
    return false;
  }
};

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    size_t l1 = s1.size();
    size_t l2 = s2.size();
    if (l1 + l2 != s3.size()) {
      return false;
    }
    std::vector<std::vector<bool>> D1(l1 + 1);
    for (auto& row : D1) {
      row.resize(l2 + 1);
    }
    std::vector<std::vector<bool>> D2(l1 + 1);
    for (auto& row : D2) {
      row.resize(l2 + 1);
    }
    D1[0][0] = true;
    D2[0][0] = true;
    int i = 1;
    while (i <= l1) {
      if (s1[i - 1] == s3[i - 1]) {
        D1[i][0] = D2[i][0] = true;
        i++;
      } else {
        while (i <= l1) {
          D1[i][0] = D2[i][0] = false;
          i++;
        }
      }
    }

    int j = 1;
    while (j <= l2) {
      if (s2[j - 1] == s3[j - 1]) {
        D1[0][j] = D2[0][j] = true;
        j++;
      } else {
        while (j <= l2) {
          D1[0][j] = D2[0][j] = false;
          j++;
        }
      }
    }

    for (int i = 1; i <= l1; ++i) {
      for (int j = 1; j <= l2; ++j) {
        if (s1[i - 1] == s3[i + j - 1]) {
          D1[i][j] = D1[i - 1][j] || D2[i - 1][j];
        } else {
          D1[i][j] = false;
        }
        if (s2[j - 1] == s3[i + j - 1]) {
          D2[i][j] = D1[i][j - 1] || D2[i][j - 1];
        } else {
          D2[i][j] = false;
        }
      }
    }
    return D1[l1][l2] || D2[l1][l2];
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");

  return 0;
}