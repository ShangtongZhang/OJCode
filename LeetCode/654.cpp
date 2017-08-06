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
  TreeNode* build(int l, int r, std::vector<int>& nums) {
    if (r <= l)
      return NULL;
    int maxValue = std::numeric_limits<int>::min();
    int maxPos = -1;
    for (int i = l; i < r; ++i) {
      if (nums[i] >= maxValue) {
        maxValue = nums[i];
        maxPos = i;
      }
    }
    TreeNode* node = new TreeNode(maxValue);
    node->left = build(l, maxPos, nums);
    node->right = build(maxPos + 1, r, nums);
    return node;
  }
  TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    return build(0, nums.size(), nums);
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}