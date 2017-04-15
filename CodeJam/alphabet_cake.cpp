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

char map[30][30];
int R;
int C;

bool isRowEmpty(int row) {
  for (int j = 0; j < C; ++j) {
    if (map[row][j] != '?') {
      return false;
    }
  }
  return true;
}

void copyRow(int dst, int src) {
  for (int j = 0; j < C; ++j) {
    map[dst][j] = map[src][j];
  }
}

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T;
  std::cin >> T;
  for (int caseInd = 1; caseInd <= T; ++caseInd) {
    std::cin >> R >> C;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        std::cin >> map[i][j];
      }
    }

    for (int i = 0; i < R; ++i) {
      if (isRowEmpty(i)) {
        if (i == 0) {
          int j = 1;
          while (isRowEmpty(j)) {
            ++j;
          }
          for (int k = 0; k < j; ++k) {
            copyRow(k, j);
          }
        } else {
          copyRow(i, i - 1);
        }
      }
    }

    for (int i = 0; i < R; ++i) {
      int preJ = 0;
      int j = 0;
      while (j < C) {
        if (map[i][j] != '?') {
          for (int k = preJ; k < j; ++k) {
            map[i][k] = map[i][j];
          }
          preJ = j + 1;
        }
        ++j;
      }
      for (int k = preJ; k < C; ++k) {
        map[i][k] = map[i][preJ - 1];
      }
    }

    std::cout << "Case #" << caseInd << ":" << std::endl;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        std::cout << map[i][j];
      }
      std::cout << std::endl;
    }
  }

  return 0;
}