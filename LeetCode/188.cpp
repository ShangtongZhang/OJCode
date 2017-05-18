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

class Solution {
public:
  int maxProfit(int k, std::vector<int> &prices) {
    if (prices.size() == 1 || prices.empty()) {
      return 0;
    }

    if (k > prices.size() / 2) {
      int profit = 0;
      for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
          profit += prices[i] - prices[i - 1];
        }
      }
      return profit;
    }
    std::vector<std::vector<int>> profit(prices.size());
    for (auto& row : profit) {
      row.resize(k + 1, 0);
    }
    for (int j = 1; j <= k; ++j) {
      int preMaxProfit = -prices[0];
      for (int i = 1; i < prices.size(); ++i) {
        profit[i][j] = std::max(profit[i - 1][j], prices[i] + preMaxProfit);
        preMaxProfit = std::max(preMaxProfit, profit[i - 1][j - 1] - prices[i]);
      }
    }
    return profit[prices.size() - 1][k];
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  std::vector<int> prices{3,3,5,0,0,3,1,4};
  Solution s;
  std::cout << s.maxProfit(2, prices);

  return 0;
}