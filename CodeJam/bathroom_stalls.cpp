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

class Node {
public:
  int l;
  int r;
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  auto cmp = [](const Node& n1, const Node& n2) {
    int s1 = n1.r - n1.l;
    int s2 = n2.r - n2.l;
    if (s1 != s2) {
      return s1 < s2;
    }
    return n2.l < n1.l;
  };

  int T;
  std::cin >> T;
  for (int caseInd = 1; caseInd <= T; ++caseInd) {
    int N, K;
    std::cin >> N >> K;
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);
    pq.emplace(Node{0, N + 1});
    for (int i = 0; i < K; ++i) {
      auto node = pq.top();
      pq.pop();
      int pos = (node.l + node.r) / 2;
      pq.push(Node{node.l, pos});
      pq.push(Node{pos, node.r});
      if (i == K - 1) {
        int LS = pos - node.l - 1;
        int RS = node.r - pos - 1;
        std::cout << "Case #" << caseInd << ": " << std::max(LS, RS) << " " << std::min(LS, RS) << std::endl;
      }
    }
  }

  return 0;
}