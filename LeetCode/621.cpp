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
  int leastInterval(std::vector<char> &tasks, int n) {
    if (n == 0) {
      return tasks.size();
    }
    std::map<char, int> count;
    for (auto c : tasks) {
      count[c] += 1;
    }
    std::vector<int> info;
    for (auto it = count.begin(); it != count.end(); ++it) {
      info.push_back(it->second);
    }
    std::sort(info.begin(), info.end(), std::greater<int>());
    return solve(info, n);
  }

  int solve(std::vector<int> &info, int n) {
    if (info.empty()) { return 0; }
    if (n + 1 >= info.size()) {
      int i = 0;
      while (i < info.size() && info[i] == info.front()) { i++; }
      return (info.front() - 1) * (n + 1) + i;
    }
    for (int i = 0; i < n + 1; ++i) {
      info[i]--;
    }
    std::vector<int> newInfo;
    for (int i = 0; i < info.size(); ++i) {
      if (info[i] == 0) { continue; }
      newInfo.push_back(info[i]);
    }
    std::sort(newInfo.begin(), newInfo.end(), std::greater<int>());
    return n + 1 + solve(newInfo, n);
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<char> tasks{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  std::cout << s.leastInterval(tasks, 2);

  return 0;
}