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

constexpr int MAX_C = 105;
constexpr int MAX_Q = 10005;
int db[MAX_C][MAX_C];

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  int caseInd = 1;
  while (true) {
    int C, S, Q;
    std::cin >> C >> S >> Q;
    if (!C && !S && !Q) {
      break;
    }
    std::fill(&db[0][0], &db[0][0] + MAX_C * MAX_C, MAX_Q);
    while (S--) {
      int v1, v2, noise;
      std::cin >> v1 >> v2 >> noise;
      db[v1][v2] = db[v2][v1] = noise;
    }
    for (int i = 1; i <= C; ++i) {
      db[i][i] = 0;
    }
    for (int k = 1; k <= C; ++k) {
      for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= C; ++j) {
          if (db[i][j] > std::max(db[i][k], db[k][j])) {
            db[i][j] = std::max(db[i][k], db[k][j]);
          }
        }
      }
    }
    if (caseInd > 1) {
      std::cout << std::endl;
    }
    std::cout << "Case #" << caseInd << std::endl;
    while (Q--) {
      int v1, v2;
      std::cin >> v1 >> v2;
      if (db[v1][v2] == MAX_Q) {
        std::cout << "no path" << std::endl;
      } else {
        std::cout << db[v1][v2] << std::endl;
      }
    }
    caseInd += 1;

  }

  return 0;
}