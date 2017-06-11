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
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (!t1 && !t2) { return NULL; }
    if (!t1) { return t2; }
    if (!t2) { return t1; };
    TreeNode* node = new TreeNode(t1->val + t2->val);
    node->left = mergeTrees(t1->left, t2->left);
    node->right = mergeTrees(t1->right, t2->right);
    return node;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}