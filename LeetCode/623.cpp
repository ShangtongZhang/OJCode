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
  TreeNode *addOneRow(TreeNode *root, int v, int d) {
    if (d == 1) {
      TreeNode* node = new TreeNode(v);
      node->left = root;
      return node;
    }
    root->left = add(root->left, v, d - 1, true);
    root->right = add(root->right, v, d - 1, false);
    return root;
  }

  TreeNode* add(TreeNode* root, int v, int d, bool left) {
    if (root == NULL) {
      if (d == 1) {
        return new TreeNode(v);
      }
      return NULL;
    }
    if (d == 1) {
      TreeNode* node = new TreeNode(v);
      if (left) {
        node->left = root;
      } else {
        node->right = root;
      }
      return node;
    }
    root->left = add(root->left, v, d - 1, true);
    root->right = add(root->right, v, d - 1, false);
    return root;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

//  TreeNode* root = new TreeNode

  return 0;
}