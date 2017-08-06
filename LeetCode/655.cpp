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
  std::vector<std::vector<std::string>> build(int row, int col) {
    std::vector<std::vector<std::string>> res(row);
    for (auto &r : res) {
      r.resize(col);
    }
    return res;
  }
  void fill(std::vector<std::vector<std::string>>& src, std::vector<std::vector<std::string>>& target) {
    int diff = target.front().size() - src.front().size();
    for (auto& row : src) {
      for (int i = 0; i < diff / 2; ++i) {
        row.insert(row.begin(), "");
      }
      for (int i = 0; i < diff / 2; ++i) {
        row.push_back("");
      }
    }
    std::vector<std::string> tail(target.front().size());
    while (src.size() < target.size()) {
      src.push_back(tail);
    }
  }
  int height(TreeNode* root) {
    if (!root) return 0;
    int hL = height(root->left);
    int hR = height(root->right);
    return 1 + std::max(hL, hR);
  }

  void pad(TreeNode* root, int height) {
    if (height <= 1) return;
    if (!root->left) {
      root->left = new TreeNode(std::numeric_limits<int>::max());
    }
    if (!root->right) {
      root->right = new TreeNode(std::numeric_limits<int>::max());
    }
    pad(root->left, height - 1);
    pad(root->right, height - 1);
  }

  std::vector<std::vector<std::string>> printTree(TreeNode *root) {
    int h = height(root);
    pad(root, h);
    if (!root) return {{""}};
    auto left = printTree(root->left);
    auto right = printTree(root->right);
    if (!root->left && !root->right) {
      std::string tmp;
      if (root->val != std::numeric_limits<int>::max()) {
        tmp = std::to_string(root->val);
      }
      return {{tmp}};
    }
    if (left.size() < right.size()) {
      fill(left, right);
    }
    if (right.size() < left.size()) {
      fill(right, left);
    }
    std::vector<std::string> head;
    for (int i = 0; i < left.front().size(); ++i) {
      head.push_back("");
    }
    std::string tmp;
    if (root->val != std::numeric_limits<int>::max()) {
      tmp = std::to_string(root->val);
    }
    head.push_back(tmp);
    for (int i = 0; i < left.front().size(); ++i) {
      head.push_back("");
    }
    for (int i = 0; i < left.size(); ++i) {
      left[i].push_back("");
      left[i].insert(left[i].end(), right[i].begin(), right[i].end());
    }
    left.insert(left.begin(), head);
    return left;
  }

};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->left->left = new TreeNode(4);
  root->right = new TreeNode(5);
  auto res = s.printTree(root);
  return 0;
}