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

int N, P;
int weights[55];

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T;
  std::cin >> T;
  for (int caseInd = 1; caseInd <= T; ++caseInd) {
    std::cin >> N >> P;
    for (int i = 0; i < N; ++i) {
      std::cin >> weights[i];
    }
    std::vector<std::vector<int>> packages(N);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < P; ++j) {
        packages[i].resize(P);
        std::cin >> packages[i][j];
      }
      std::sort(packages[i].begin(), packages[i].end());
    }
    int kits = 0;
    while (!packages[0].empty()) {
      float low = -1;
      float high = std::numeric_limits<float>::max();
      std::vector<int> pos;
      bool ok;
      for (int i = 0; i < N; ++i) {
        ok = false;
        for (int j = packages[i].size() - 1; j >= 0; --j) {
          int pack = packages[i][j];
          float newLow = pack / (1.1 * weights[i]);
          float newHigh = pack / (0.9 * weights[i]);
          newLow = std::max(low, newLow);
          newHigh = std::min(high, newHigh);
          if (std::floor(newHigh) >= std::ceil(newLow)) {
            pos.push_back(j);
            ok = true;
            low = newLow;
            high = newHigh;
            break;
          }
        }
        if (!ok) {
          break;
        }
      }
      if (ok) {
        kits++;
        for (int i = 0; i < N; ++i) {
          packages[i].erase(packages[i].begin() + pos[i]);
        }
      } else {
        packages[0].pop_back();
      }
    }
    std::cout << "Case #" << caseInd << ": " << kits << std::endl;
  }

  return 0;
}