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
    int t;
    int d;
  };
  std::unordered_map<int, int> compress(std::unordered_map<int, int>& info) {
    std::unordered_map<int, int> compressed;
    for (auto it = info.begin(); it != info.end(); ++it) {
      if (compressed.count(it->second)) {
        compressed[it->second] = std::min(compressed[it->second], it->first);
      } else {
        compressed[it->second] = it->first;
      }
    }
    std::unordered_map<int, int> rtl;
    for (auto it = compressed.begin(); it != compressed.end(); ++it) {
      rtl[it->second] = it->first;
    }
    return rtl;
  }
  int scheduleCourse(std::vector<std::vector<int>>& courses) {
    std::vector<Node> cs;
    for (auto& c : courses) {
      cs.push_back(Node{c[0], c[1]});
    }
    auto cmp = [](Node& n1, Node& n2) {
      if (n1.d != n2.d) {
        return n1.d < n2.d;
      }
      return n1.t < n2.t;
    };
    std::sort(cs.begin(), cs.end(), cmp);
    std::vector<std::unordered_map<int, int>> D(cs.size());
    if (cs[0].d >= cs[0].t) {
      D[0][cs[0].t] = 1;
    }
    D[0][0] = 0;
    for (int i = 1; i < cs.size(); ++i) {
      D[i] = D[i - 1];
      for (auto it = D[i - 1].begin(); it != D[i - 1].end(); ++it) {
        int end = it->first + cs[i].t;
        if (end <= cs[i].d) {
          D[i][end] = std::max(D[i][end], it->second + 1);
        }
      }
      D[i] = compress(D[i]);
    }
    int count = 0;
    for (auto it = D.back().begin(); it != D.back().end(); ++it) {
      count = std::max(count, it->second);
    }
    return count;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
//  std::vector<std::vector<int>> courses{{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  std::vector<std::vector<int>> courses{{5, 5}, {4, 6}, {2, 6}};
  std::cout << s.scheduleCourse(courses);

  return 0;
}