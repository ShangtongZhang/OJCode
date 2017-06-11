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
  class Node {
  public:
    char num;
    int pos;

    bool operator<(const Node &n) {
      if (num != n.num) { return num < n.num; }
      return pos < n.pos;
    }
  };

  std::string removeKdigits(std::string num, int k) {
    if (k == num.size()) { return "0"; }
    std::string res;
    int cur = 0;
    while (k) {
      char minDigit = '9' + 1;
      int minPos = 0;
      for (int i = cur; i <= cur + k; ++i) {
        if (minDigit > num[i]) {
          minDigit = num[i];
          minPos = i;
        }
      }
      if (minDigit == '0' && res.empty()) {
        k -= minPos - cur;
        while (minPos < num.size() && num[minPos] == '0') { minPos++; }
        cur = minPos;
        if (minPos == num.size()) { break; }
      } else {
        res += minDigit;
        k -= minPos - cur;
        cur = minPos + 1;
      }
      if (k >= num.size() - cur) {
        cur = num.size();
        break;
      }
    }
    res += num.substr(cur);
    if (res.empty()) { res = "0"; }
    return res;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::cout << s.removeKdigits("1107", 1);

  return 0;
}