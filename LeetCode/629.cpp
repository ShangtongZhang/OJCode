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
    int kInversePairs(int n, int k) {
      int D[1001][1001];
      int M = 1000000000 + 7;
      for (int i = 0; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (i == 0) {
            D[n][k] = 1;
          }
        }
      }

    }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}