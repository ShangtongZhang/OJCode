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
  std::vector<int> killProcess(std::vector<int> &pid, std::vector<int> &ppid, int kill) {
    std::unordered_map<int, std::set<int>> procs;
    for (int i = 0; i < ppid.size(); ++i) {
      if (procs.count(ppid[i]) == 0) {
        procs[ppid[i]] = std::set<int>();
      }
      procs[ppid[i]].insert(pid[i]);
    }
    std::queue<int> toBeKilled;
    std::vector<int> res;
    toBeKilled.push(kill);
    while (!toBeKilled.empty()) {
      int p = toBeKilled.front();
      toBeKilled.pop();
      res.push_back(p);
      if (procs.count(p)) {
        for (auto& ch : procs[p]) {
          toBeKilled.push(ch);
        }
        procs.erase(p);
      }
    }
    return res;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}