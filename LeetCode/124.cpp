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
  int maxPathSum(TreeNode *root) {
    int c1 = std::numeric_limits<int>::min();
    int c2 = search(root, c1);
    return std::max(c1, c2);
  }

  int search(TreeNode* cur, int& maxSum) {
    int res = cur->val;
    int newMaxSum = cur->val;
    if (cur->left) {
      int lSum = search(cur->left, maxSum);
      res = std::max(res, cur->val + lSum);
      if (lSum > 0) {
        newMaxSum += lSum;
      }
    }
    if (cur->right) {
      int rSum = search(cur->right, maxSum);
      res = std::max(res, cur->val + rSum);
      if (rSum > 0) {
        newMaxSum += rSum;
      }
    }
    maxSum = std::max(maxSum, newMaxSum);
    return res;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  return 0;
}