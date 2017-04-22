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

int D, N;

class Node {
public:
  int p;
  int v;
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T;
  std::cin >> T;
  for (int caseInd = 1; caseInd <= T; ++caseInd) {
    std::cin >> D >> N;
    std::vector<Node> info(N);
    for (auto& node : info) {
      std::cin >> node.p >> node.v;
    }
    std::sort(info.begin(), info.end(), [](const Node& n1, const Node& n2) {
      return n1.p < n2.p;
    });
    double time = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (i == N - 1
          || info[i].v <= info[i + 1].v
          || info[i].v * time < D - info[i].p) {
        time = (D - info[i].p) / (double)info[i].v;
      }
    }
    std::cout << "Case #" << caseInd << ": " << std::fixed << std::setprecision(6) << D / time << std::endl;

  }

  return 0;
}