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
  std::string solveEquation(std::string equation) {
    int pos = equation.find('=');
    std::string lhs = equation.substr(0, pos);
    std::string rhs = equation.substr(pos + 1);
    int xCoef = 0;
    int cCoef = 0;
    read(lhs, xCoef, cCoef);
    int xCoefR = 0;
    int cCoefR = 0;
    read(rhs, xCoefR, cCoefR);
    xCoef -= xCoefR;
    cCoef = cCoefR - cCoef;
    if (xCoef == 0) {
      if (cCoef == 0) {
        return "Infinite solutions";
      }
      return "No solution";
    }
    return "x=" + std::to_string(cCoef / xCoef);
  }

  void read(std::string& exp, int& xCoef, int& cCoef) {
    int pos = 0;
    while (pos < exp.size()) {
      int num = 0;
      if (readInt(exp, pos, num)) {
        cCoef += num;
      } else {
        xCoef += num;
      }
    }
  }

  bool readInt(std::string& exp, int& pos, int& num) {
    int sign = 1;
    if (exp[pos] == '-') {
      sign = -1;
      pos++;
    }
    if (exp[pos] == '+') { pos++; }
    bool noCoef = true;
    while (pos < exp.size() && exp[pos] >= '0' && exp[pos] <= '9') {
      num = num * 10 + (exp[pos] - '0');
      noCoef = false;
      pos++;
    }
    if (pos < exp.size()) {
      if (exp[pos] == 'x') {
        if (num == 0 && noCoef) {
          num = sign;
        } else {
          num *= sign;
        }
        pos++;
        return false;
      }
    }
    num *= sign;
    return true;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.solveEquation("x+5-3+x=6+x-2");
//  std::cout << s.solveEquation("0x=0");
//  std::cout << s.solveEquation("x=x+2");
//  std::cout << s.solveEquation("2x+3x-6x=x+2");


  return 0;
}