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

class Node {
public:
  Node* left;
  Node* right;
  Node* parent;
  int sum;
  int l;
  int r;
  int mid;
  Node(int l, int r, Node* parent) :
          left(NULL), right(NULL), parent(parent), l(l), r(r), sum(0) {
    mid = (l + r) / 2;
  }
};

Node* build(std::vector<int>& data, int l, int r, Node* parent, std::vector<Node*>& nodes) {
  if (l == r) {
    return NULL;
  }
  if (l + 1 == r) {
    Node* node = new Node(l, r, parent);
    node->sum = data[l];
    nodes[l] = node;
    return node;
  }
  int mid = (l + r) / 2;
  Node* node = new Node(l, r, parent);
  node->left = build(data, l, mid, node, nodes);
  node->right = build(data, mid, r, node, nodes);
  if (node->left) {
    node->sum += node->left->sum;
  }
  if (node->right) {
    node->sum += node->right->sum;
  }
  return node;
}

int query(Node* root, int l, int r) {
  if (l == r) {
    return 0;
  }
  if (l == root->l && r == root->r) {
    return root->sum;
  }
  if (r <= root->mid) {
    return query(root->left, l, r);
  }
  if (l >= root->mid) {
    return query(root->right, l, r);
  }
  return query(root->left, l, root->mid) + query(root->right, root->mid, r);
}

void inc(int pos, std::vector<Node*>& nodes) {
  Node* node = nodes[pos];
  while (node) {
    node->sum += 1;
    node = node->parent;
  }
}

class Wrapper {
public:
  int num;
  int index;
};

bool operator < (const Wrapper& w1, const Wrapper& w2) {
  if (w1.num != w2.num) {
    return w1.num < w2.num;
  }
  return w1.index < w2.index;
}

class SolutionSegTree {
public:
  int reversePairs(std::vector<int>& nums) {
    std::vector<int> count(nums.size(), 0);
    std::vector<Node*> nodes(nums.size(), NULL);
    Node* root = build(count, 0, count.size(), NULL, nodes);
    std::vector<Wrapper> numbers(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      numbers[i].num = nums[i];
      numbers[i].index = i;
    }
    std::queue<Wrapper> pending;
    std::sort(numbers.begin(), numbers.end());
    int res = 0;
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
      std::cout << it->num << " " << it->index << std::endl;
      if (pending.empty() || 2 * (long)pending.front().num < it->num) {
        pending.push(*it);
        inc(it->index, nodes);
        continue;
      }
      while (!pending.empty() && 2 * (long)pending.front().num > it->num) {
        res += query(root, 0, pending.front().index);
        pending.pop();
      }
      pending.push(*it);
      inc(it->index, nodes);
    }
    while (!pending.empty()) {
      res += query(root, 0, pending.front().index);
      pending.pop();
    }
    return res;
  }
};

class Solution {
public:
  int sort(int l, int r, std::vector<int>& nums) {
    if (l == r) {
      return 0;
    }
    if (l + 1 == r) {
      return 0;
    }
    int mid = (l + r) / 2;
    int count = sort(l, mid, nums);
    count += sort(mid, r, nums);
    int posL = l;
    int posR = mid;
    while (true) {
      while (posL < mid && nums[posL] <= 2 * (long)nums[posR]) {
        posL++;
      }
      count += mid - posL;
      if (posL == mid) {
        break;
      }
      posR++;
      if (posR == r) {
        break;
      }
    }
    std::vector<int> sorted;
    posL = l;
    posR = mid;
    while (true) {
      while (posL < mid && nums[posL] < nums[posR]) {
        sorted.push_back(nums[posL]);
        posL++;
      }
      if (posL == mid) {
        while (posR != r) {
          sorted.push_back(nums[posR]);
          posR++;
        }
        break;
      }
      sorted.push_back(nums[posR]);
      posR++;
      if (posR == r) {
        while (posL != mid) {
          sorted.push_back(nums[posL]);
          posL++;
        }
        break;
      }
    }
    std::copy(sorted.begin(), sorted.end(), nums.begin() + l);
    return count;
  }

  int reversePairs(std::vector<int>& nums) {
    return sort(0, nums.size(), nums);
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

//  std::vector<int> nums{1,3,2,3,1};
//  std::vector<int> nums{2,4,3,5,1};
//  std::vector<int> nums{2, 2, -2, -2, -2, 2};
  std::vector<int> nums{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
//  std::vector<int> nums{233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004};
  Solution s;
  std::cout << s.reversePairs(nums) << std::endl;

  return 0;
}