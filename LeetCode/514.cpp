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
    size_t pos;
    std::string key;
    int steps;
  };
  int findRotateSteps(std::string ring, std::string key) {
    Node n{0, "", 0};
    std::queue<Node> info;
    auto cmp = [] (const Node& n1, const Node& n2) {
      if (n1.key.size() != n2.key.size()) {
        return n1.key.size() < n2.key.size();
      }
      return n1.steps > n2.steps;
    };
    info.push(n);
    Node cur;
    int maxKeyLen = -1;
    int minSteps = std::numeric_limits<int>::max();
    std::unordered_map<std::string, std::unordered_map<size_t, int>> cache;
    while (!info.empty()) {
      cur = info.front();
      info.pop();
      if (cur.key == key) {
        break;
      }
      if (cache.count(cur.key) && cache[cur.key].count(cur.pos) && cache[cur.key][cur.pos] <= cur.steps) {
        continue;
      } else {
        cache[cur.key][cur.pos] = cur.steps;
      }
      if (cur.key.size() < key.size() && key[cur.key.size()] == ring[cur.pos]) {
        info.push(Node{cur.pos, cur.key + ring[cur.pos], cur.steps + 1});
      }
      info.push(Node{(cur.pos + 1) % ring.size(), cur.key, cur.steps + 1});
      info.push(Node{(cur.pos + ring.size() - 1) %  ring.size(), cur.key, cur.steps + 1});

    }
    return cur.steps;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
//  std::cout << s.findRotateSteps("godding", "gd");
  std::cout << s.findRotateSteps("ababcab", "acbaacba");

  return 0;
}