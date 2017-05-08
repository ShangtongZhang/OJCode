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
  std::vector<int> kinds;
  std::vector<int> count;
  std::vector<std::vector<std::vector<int>>> cache;
  int removeBoxes(std::vector<int> &boxes) {
    kinds.clear();
    count.clear();
    bool first = true;
    for (size_t i = 0; i < boxes.size(); ++i) {
      if (first) {
        kinds.push_back(boxes[i]);
        count.push_back(1);
        first = false;
      } else {
        if (boxes[i] != boxes[i - 1]) {
          first = true;
          i--;
        } else {
          count.back() += 1;
        }
      }
    }
    int cache[101][101][101] = {0};
    return remove(cache, 0, kinds.size(), 0);
  }

  template <int N>
  int remove(int cache[N][N][N], int l, int r, int k) {
    if (cache[l][r][k] > 0) {
      return cache[l][r][k];
    }
    if (l + 1 == r) {
      cache[l][r][k] = (count[l] + k) * (count[l] + k);
      return cache[l][r][k];
    }
    cache[l][r][k] = (count[l] + k) * (count[l] + k) + remove(cache, l + 1, r, 0);
    for (int i = l + 1; i < r; ++i) {
      if (kinds[i] == kinds[l]) {
        cache[l][r][k] = std::max(cache[l][r][k], remove(cache, l + 1, i, 0) + remove(cache, i, r, count[l] + k));
      }
    }
    return cache[l][r][k];
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
//  std::vector<int> boxs{1, 3, 2, 2, 2, 3, 4, 3, 1};
//  std::vector<int> boxs{4, 4, 1, 4, 4};
  std::vector<int> boxs{3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5, 8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3, 9, 8, 8, 6, 5, 3, 7, 4, 9, 6, 3, 9, 4, 3, 5, 10, 7, 6, 10, 7};
  std::cout << s.removeBoxes(boxs) << std::endl;
  return 0;
}