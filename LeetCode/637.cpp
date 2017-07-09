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
  std::vector<double> averageOfLevels(TreeNode *root) {
    std::vector<double> avg;
    std::queue<TreeNode*> node;
    std::queue<int> level;
    node.push(root);
    level.push(0);
    int curLevel = 0;
    double curSum = 0;
    int curCount = 0;
    while (!node.empty()) {
      TreeNode* cur = node.front();
      node.pop();
      int l = level.front();
      level.pop();
      if (l != curLevel) {
        avg.push_back(curSum / curCount);
        curSum = curCount = 0;
        curLevel = l;
      }
      curSum += cur->val;
      curCount++;
      if (cur->left) {
        node.push(cur->left);
        level.push(curLevel + 1);
      }
      if (cur->right) {
        node.push(cur->right);
        level.push(curLevel + 1);
      }
    }
    if (curCount) {
      avg.push_back(curSum / curCount);
    }
    return avg;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  TreeNode* t = new TreeNode(5);
  t->left = new TreeNode(14);
  t->left->left = new TreeNode(1);
  Solution s;
  s.averageOfLevels(t);

  return 0;
}