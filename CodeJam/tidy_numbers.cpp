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

bool solve(std::string& num, size_t pos, int curMax, std::string& ans) {
  if (pos >= num.size()) {
    return true;
  }
  char c = num[pos];
  if (c < curMax) {
    return false;
  }
  ans.push_back(c);
  if (solve(num, pos + 1, c, ans)) {
    return true;
  }
  ans.pop_back();
  c--;
  if (c < curMax) {
    return false;
  }
  ans.push_back(c);
  pos++;
  while (pos < num.size()) {
    ans.push_back('9');
    pos++;
  }
  return true;
}

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T;
  std::cin >> T;
  for (int caseInd = 1; caseInd <= T; ++caseInd) {
    long long int N;
    std::cin >> N;
    auto str = std::to_string(N);
    std::string ans;
    if (!solve(str, 0, 0, ans)) {
      for (size_t i = 1; i < str.size(); ++i) {
        ans.push_back('9');
      }
    }
    if (ans.front() == '0' && ans.size() >= 1) {
      ans = ans.substr(1, ans.size() - 1);
    }
    std::cout << "Case #" << caseInd << ": " << ans << std::endl;
  }
  return 0;
}