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
  int calculate(std::string s) {
    int pos = 0;
    while (pos < s.size() && s[pos] == ' ') { pos++; };
    return solve(s, pos);
  }

  int readNum(std::string &s, int &pos) {
    int res = 0;
    while (pos < s.size()) {
      if (isDigit(s[pos])) {
        res *= 10;
        res += s[pos] - '0';
        pos++;
      } else {
        break;
      }
    }
    while (pos < s.size() && s[pos] == ' ') { pos++; };
    return res;
  }

  char readOp(std::string& s, int& pos) {
    while (s[pos] == ' ') { pos++; };
    char op = s[pos++];
    while (pos < s.size() && s[pos] == ' ') { pos++; };
    return op;
  }

  bool isDigit(char c) {
    return '0' <= c && c <= '9';
  }

  int solve(std::string& s, int& pos) {
    std::vector<int> nums;
    int res;
    char op;
    while (pos < s.size()) {
      if (isDigit(s[pos])) {
        int i = readNum(s, pos);
        nums.push_back(i);
      } else {
        char tmp = readOp(s, pos);
        if (tmp == '(') {
          nums.push_back(solve(s, pos));
        } else if (tmp == ')') {
          break;
        } else {
          op = tmp;
        }
      }
      if (nums.size() == 2) {
        if (op == '+') {
          nums[0] = nums[0] + nums[1];
        } else if (op == '-') {
          nums[0] = nums[0] - nums[1];
        }
        nums.pop_back();
      }
    }
    return nums[0];
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.calculate("(1+(4+5+2)-3)+(6+8)");

  return 0;
}