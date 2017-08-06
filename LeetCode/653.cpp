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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::unordered_map<int, int> info;
  void travel(TreeNode* root) {
    if (!root) return;
    info[root->val] += 1;
    travel(root->left);
    travel(root->right);
  }
  bool findTarget(TreeNode *root, int k) {
    info.clear();
    travel(root);
    for (auto it = info.begin(); it != info.end(); ++it) {
      auto target = info.find(k - it->first);
      if (target == info.end()) continue;
      if (target != it) return true;
      if (it->second >= 2) { return true; }
    }
    return false;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}