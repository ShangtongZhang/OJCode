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

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T;
  std::cin >> T;
  int caseInd = 1;
  while (T--) {
    std::string cakes;
    int K;
    std::cin >> cakes >> K;
    std::set<std::string> visited;
    std::queue<std::string> nodes;
    std::queue<int> depth;

    std::string goal = cakes;
    for (auto& c : goal) {
      c = '+';
    }

    nodes.push(cakes);
    depth.push(0);
    visited.insert(cakes);
    int dist = -1;
    while (!nodes.empty()) {
      std::string curNode = nodes.front();
      nodes.pop();
      int curDepth = depth.front();
      depth.pop();
      if (curNode == goal) {
        dist = curDepth;
        break;
      }
      for (int i = 0; i < curNode.size(); ++i) {
        if (i + K > curNode.size()) {
          break;
        }
        std::string nextNode(curNode);
        for (int j = i; j < i + K; ++j) {
          if (nextNode[j] == '+') {
            nextNode[j] = '-';
          } else {
            nextNode[j] = '+';
          }
        }
       if (visited.count(nextNode)) {
          continue;
        }
        nodes.push(nextNode);
        depth.push(curDepth + 1);
        visited.insert(nextNode);
      }
    }
    std::cout << "Case #" << caseInd << ": ";
    if (dist >= 0) {
      std::cout << dist;
    } else {
      std::cout << "IMPOSSIBLE";
    }
    std::cout << std::endl;
    caseInd++;
  }

  return 0;
}