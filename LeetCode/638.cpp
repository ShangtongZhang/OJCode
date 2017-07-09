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
    int cost;
    std::vector<int> need;
  };

  class Compare {
  public:
    bool operator()(Node &n1, Node &n2) {
      return n1.cost > n2.cost;
    }
  };

  int shoppingOffers(std::vector<int> &price,
                     std::vector<std::vector<int>> &special,
                     std::vector<int> &needs) {
    std::priority_queue<Node, std::vector<Node>, Compare> info;
    info.push(Node{0, needs});
    while (!info.empty()) {
      Node cur = info.top();
      info.pop();
      if (check(cur.need)) {
        return cur.cost;
      }
      Node next = cur;
      for (int i = 0; i < cur.need.size(); ++i) {
        next.cost += next.need[i] * price[i];
        next.need[i] = 0;
      }
      info.push(next);
      for (auto &offer : special) {
        Node next = cur;
        if (substract(next.need, offer)) {
          next.cost += offer.back();
          info.push(next);
        }
      }
    }
  }

  bool check(std::vector<int> &need) {
    for (int i = 0; i < need.size(); ++i) {
      if (need[i]) {
        return false;
      }
    }
    return true;
  }

  bool substract(std::vector<int> &need, std::vector<int> &offer) {
    for (int i = 0; i < need.size(); ++i) {
      need[i] -= offer[i];
      if (need[i] < 0) { return false; }
    }
    return true;
  }

};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> price{2, 5};
  std::vector<std::vector<int>> offer{{3,0,5}, {1,2,10}};
  std::vector<int> needs{3, 2};

//  std::vector<int> price{4, 3, 2, 9, 8, 8};
//  std::vector<std::vector<int>> offer{{1, 5, 5, 1, 4, 0, 18},
//                                      {3, 3, 6, 6, 4, 2, 32}};
//  std::vector<int> needs{6, 5, 5, 6, 4, 1};
  std::cout << s.shoppingOffers(price, offer, needs);

  return 0;
}