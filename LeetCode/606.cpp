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
  std::string tree2str(TreeNode *t) {
    if (!t) {
      return "";
    }
    std::string res;
    build(t, res);
    return res;
  }

  void build(TreeNode* root, std::string& res) {
    res += (std::to_string(root->val));
    if (!root->left && !root->right) {
      return;
    }
    if (root->left) {
      res += '(';
      build(root->left, res);
      res += ')';
      if (root->right) {
        res += '(';
        build(root->right, res);
        res += ')';
      }
    } else {
      res += "()(";
      build(root->right, res);
      res += ')';
    }
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  TreeNode* t = new TreeNode(1);
  t->right = new TreeNode(3);
  t->left = new TreeNode(2);
  t->left->left = new TreeNode(4);
  Solution s;
  std::cout << s.tree2str(t);

  return 0;
}