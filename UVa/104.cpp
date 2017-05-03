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

constexpr int MAX_N = 24;
double D[MAX_N][MAX_N][MAX_N];
int T[MAX_N][MAX_N][MAX_N];
int N;

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  while (std::cin >> N) {
    std::memset(D, 0, sizeof(D));
    std::memset(T, 0, sizeof(T));
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (i != j) {
          std::cin >> D[i][j][1];
        } else {
          D[i][j][0] = 1;
        }
      }
    }
    for (int length = 1; length <= N; ++length) {
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          for (int k = 1; k <= N; ++k) {
            double newProfit = D[i][k][length - 1] * D[k][j][1];
            if (D[i][j][length] < newProfit) {
              D[i][j][length] = newProfit;
              T[i][j][length] = k;
            }
          }
        }
      }
    }
    int length = 1;
    bool possible = false;
    while (length <= N && !possible) {
      for (int i = 1; i <= N; ++i) {
        if (D[i][i][length] >= 1.01) {
          possible = true;
          std::vector<int> path;
          path.push_back(i);
          int k = T[i][i][length];
          while (length > 1) {
            length--;
            path.push_back(k);
            k = T[i][k][length];
          }
          path.push_back(i);
          for (auto it = path.rbegin(); it != path.rend(); ++it) {
            if (it != path.rbegin()) {
              std::cout << " ";
            }
            std::cout << *it;
          }
          std::cout << std::endl;
          break;
        }
      }
      length++;
    }
    if (!possible) {
      std::cout << "no arbitrage sequence exists" << std::endl;
    }
  }

  return 0;
}