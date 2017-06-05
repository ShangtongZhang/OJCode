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
    int max;
    int l;
    int r;
    int m;
    Node* lChild;
    Node* rChild;
    Node* parent;
    Node (int l, int r) : l(l), r(r), lChild(NULL), rChild(NULL), parent(NULL) {
      m = (l + r) / 2;
    }
  };
  Node* build(int l, int r) {
    Node* node = new Node(l, r);
    if (l == r) {
      node->max = data[l];
      map[l] = node;
      return node;
    }
    int m = (l + r) / 2;
    node->lChild = build(l, m);
    node->rChild = build(m + 1, r);
    node->max = std::max(node->lChild->max, node->rChild->max);
    node->lChild->parent = node;
    node->rChild->parent = node;
    return node;
  }
  int query(Node* cur, int l, int r) {
    if (cur->l == l && cur->r == r) {
      return cur->max;
    }
    if (r <= cur->m) {
      return query(cur->lChild, l, r);
    }
    if (l >= cur->m + 1) {
      return query(cur->rChild, l, r);
    }
    return std::max(query(cur->lChild, l, cur->m), query(cur->rChild, cur->m + 1, r));
  }
  std::vector<int> data;
  std::vector<Node*> map;
  int trap(std::vector<int> &height) {
    if (height.size() <= 1) {
      return 0;
    }
    data = std::move(height);
    map.resize(data.size());
    Node* root = build(0, data.size() - 1);
    int water = 0;
    int i = 0;
    while (i < data.size() - 1) {
      int maxH = query(root, i + 1, data.size() - 1);
      if (data[i] > maxH) {
        data[i] = maxH;
      }
      int j = i + 1;
      while (data[j] < data[i]) {
        water += data[i] - data[j];
        ++j;
      }
      i = j;
    }
    return water;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
//  std::vector<int> heights{0,1,0,2,1,0,1,3,2,1,2,1};
  std::vector<int> heights{4, 2, 3};
  std::cout << s.trap(heights);

  return 0;
}