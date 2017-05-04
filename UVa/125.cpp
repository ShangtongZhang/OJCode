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

constexpr int MAX_N = 33;
int map[MAX_N][MAX_N];
int N;

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  int nEdges;
  int cityIndex = 0;
  while (std::cin >> nEdges) {
    std::memset(map, 0, sizeof(map));
    N = 0;
    while (nEdges--) {
      int v1, v2;
      std::cin >> v1 >> v2;
      v1++;
      v2++;
      map[v1][v2] = 1;
      N = std::max(v1, std::max(v2, N));
    }
    for (int k = 1; k <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          map[i][j] += map[i][k] * map[k][j];
        }
      }
    }
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (map[i][j] != 0 && map[j][i] != 0) {
          map[i][j] = map[j][i] = -1;
        }
      }
    }
    for (int k = 1; k <= N; ++k) {
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          if (map[i][k] == -1 && map[k][j] != 0) {
            map[i][j] = -1;
          }
          if (map[i][k] != 0 && map[k][j] == -1) {
            map[i][j] = -1;
          }
        }
      }
    }
    std::cout << "matrix for city " << cityIndex++ << std::endl;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (j > 1) {
          std::cout << " ";
        }
        std::cout << map[i][j];
      }
      std::cout << std::endl;
    }
  }
  return 0;
}