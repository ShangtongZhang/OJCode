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

int solve(std::string& str, int m, char c) {
  int maxLen = 0;
  int l = 0;
  int r = 0;
  while (true) {
    while (r < str.size()) {
      if (str[r] != c) {
        if (m) {
          r++;
          m--;
        } else {
          break;
        }
      } else {
        r++;
      }
    }
    maxLen = std::max(maxLen, r - l);
    if (r == str.size()) { break; }
    if (str[l] != c) { m++; }
    l++;
  }
  return maxLen;
}

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  int N;
  std::cin >> N;
  std::string str;
  std::cin >> str;
  int q;
  std::cin >> q;
  while (q--) {
    int m;
    char c;
    std::cin >> m >> c;
    std::cout << solve(str, m, c) << std::endl;
  }
  return 0;
}