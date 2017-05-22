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
  int numberOfArithmeticSlices(std::vector<int> &A) {
    constexpr int MAX_N = 1002;
    int D[MAX_N][MAX_N];
    std::memset(D, 0, sizeof(D));
    int len = A.size();
    for (int i = 1; i < len; ++i) {
      for (int j = 0; j < i; ++j) {
        for (int k = 0; k < j; ++k) {
          if ((long long int)A[j] - A[k] == (long long int)A[i] - A[j]) {
            D[i][j] += D[j][k] + 1;
          }
        }
      }
    }
    int count = 0;
    for (int i = 1; i < len; ++i) {
      for (int j = 0; j < i; ++j) {
        count += D[i][j];
      }
    }
    return count;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<int> A{2, 4, 6, 8, 10};
  std::cout << s.numberOfArithmeticSlices(A);

  return 0;
}