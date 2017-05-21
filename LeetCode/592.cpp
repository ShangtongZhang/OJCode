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

class Frac {
public:
  int numerator;
  int denominator;
  std::string toString() {
    std::string str;
    if (numerator == 0) {
      str = "0/1";
      return str;
    }
    str += std::to_string(numerator);
    str += '/';
    str += std::to_string(denominator);
    return str;
  }
};

unsigned GCD(unsigned u, unsigned v) {
  while ( v != 0) {
    unsigned r = u % v;
    u = v;
    v = r;
  }
  return u;
}

Frac operator + (const Frac& f1, const Frac& f2) {
  Frac res;
  res.denominator = f1.denominator * f2.denominator;
  res.numerator = f1.denominator * f2.numerator + f2.denominator * f1.numerator;
  int gcd = GCD(std::abs(res.numerator), res.denominator);
  res.denominator /= gcd;
  res.numerator /= gcd;
  return res;
}

class Solution {
public:
    std::string fractionAddition(std::string expression) {
      if (expression[0] != '-') {
        expression = "+" + expression;
      }
      std::stringstream ss(expression);
      Frac sum;
      sum.numerator = 0;
      sum.denominator = 1;
      while (!ss.eof()) {
        Frac f;
        ss >> f.numerator;
        char tmp;
        ss >> tmp;
        ss >> f.denominator;
        sum = sum + f;
      }
      return sum.toString();
    }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.fractionAddition("5/3+1/3");

  return 0;
}