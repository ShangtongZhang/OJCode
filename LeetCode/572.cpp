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
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == NULL) {
      return false;
    }
    if (isSame(s, t)) {
      return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool isSame(TreeNode *s, TreeNode *t) {
    if (s == NULL && t == NULL) {
      return true;
    }
    if (s == NULL && t != NULL) {
      return false;
    }
    if (s != NULL && t == NULL) {
      return false;
    }
    if (s->val == t->val) {
      return isSame(s->left, t->left) && isSame(s->right, t->right);
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