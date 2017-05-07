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
  Solution() {
    MAX = 51;
    MOD = 1000000007;
  }
  int MAX;
  int MOD;
  std::vector<std::vector<std::vector<int>>> cache;
  int findPaths(int m, int n, int N, int i, int j) {
    cache.clear();
    cache.resize(MAX);
    for (auto& v1 : cache) {
      v1.resize(MAX);
      for (auto& v2: v1) {
        v2.resize(MAX, -1);
      }
    }
    return find(m, n, N, i, j);
  }

  int find(int m, int n, int N, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return 1;
    }
    if (N == 0) {
      return 0;
    }
    if (cache[i][j][N] >= 0) {
      return cache[i][j][N];
    }
    int count = find(m, n, N - 1, i - 1, j) % MOD;
    count += find(m, n, N - 1, i + 1, j) % MOD;
    count %= MOD;
    count += find(m, n, N - 1, i, j - 1) % MOD;
    count %= MOD;
    count += find(m, n, N - 1, i, j + 1) % MOD;
    count %= MOD;
    cache[i][j][N] = count;
    return count;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::cout << s.findPaths(8, 50, 23, 5, 26) << std::endl;

  return 0;
}