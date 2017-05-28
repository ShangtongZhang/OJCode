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
  int nRow;
  int nCol;
  std::vector<std::vector<int>> D;
  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    nRow = matrix.size();
    nCol = matrix.front().size();
    D.resize(nRow + 1);
    for (auto& row : D) {
      row.resize(nCol + 1);
    }
    for (int i = 1; i <= nRow; ++i) {
      for (int j = 1; j <= nCol; ++j) {
        D[i][j] = D[i - 1][j] + (matrix[i - 1][j - 1] == '1');
      }
    }
    return search(1, nCol);
  }
  int search(int l, int r) {
    if (l == r) {
      int area = 0;
      for (int i = 0; i < nRow; ++i) {
        for (int j = i + 1; j <= nRow; ++j) {
          if (j - i == D[j][l] - D[i][l]) {
            area = std::max(j - i, area);
          }
        }
      }
      return area;
    }
    int m = (l + r) / 2;
    int area = 0;
    for (int i = 0; i < nRow; ++i) {
      for (int j = i + 1; j <= nRow; ++j) {
        int curArea = 0;
        if (j - i == D[j][m] - D[i][m] && j - i == D[j][m + 1] - D[i][m + 1]) {
          curArea = (j - i) * 2;
        } else {
          break;
        }
        int k = m - 1;
        while (k >= 1) {
          if (j - i == D[j][k] - D[i][k]) {
            curArea += j - i;
            k--;
          } else {
            break;
          }
        }
        k = m + 2;
        while (k <= nCol) {
          if (j - i == D[j][k] - D[i][k]) {
            curArea += j - i;
            k++;
          } else {
            break;
          }
        }
        area = std::max(area, curArea);
      }
    }
    area = std::max(area, search(l, m));
    area = std::max(area, search(m + 1, r));
    return area;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  std::vector<std::vector<char>> m;
  std::string line;
  while (in >> line) {
    m.push_back({});
    for (auto& c : line) {
      m.back().push_back(c);
    }
  }

  Solution s;
  std::cout << s.maximalRectangle(m);

  return 0;
}