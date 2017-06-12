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
  int coinChange(std::vector<int>& coins, int amount) {
    if (coins.empty()) { return -1; }
    std::vector<int> D(amount + 1);
    for (int j = 1; j <= amount; ++j) {
      D[j] = std::numeric_limits<int>::max();
      for (int i = 0; i < coins.size(); ++i) {
        if (j >= coins[i]) {
          if (D[j - coins[i]] < std::numeric_limits<int>::max()) {
            D[j] = std::min(D[j], D[j - coins[i]] + 1);
          }
        }
      }
    }
    if (D[amount] == std::numeric_limits<int>::max()) {
      return -1;
    }
    return D[amount];
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> coins{186,419,83,408};
  std::cout << s.coinChange(coins, 6249);

  return 0;
}