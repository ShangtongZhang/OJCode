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

class Edge {
public:
  double weight;
  size_t v1;
  size_t v2;
};

bool operator < (const Edge& e1, const Edge& e2) {
  return e1.weight > e2.weight;
}

class Vertex {
public:
  double x;
  double y;
};

double dist(const Vertex& v1, const Vertex& v2) {
  double dx = v1.x - v2.x;
  double dy = v1.y - v2.y;
  return std::sqrt(dx * dx + dy * dy);
}

std::vector<int> ufs;

int find(int i) {
  if (ufs[i] != i) {
    return find(ufs[i]);
  }
  return i;
}

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T = 0;
  std::cin >> T;
  for (int caseInd = 0; caseInd < T; ++caseInd) {
    std::string dummy;
    std::getline(std::cin, dummy);
    int nPoints;
    std::cin >> nPoints;
    std::vector<Vertex> vs(nPoints);
    ufs.resize(nPoints);
    for (size_t i = 0; i < ufs.size(); ++i) {
      ufs[i] = i;
    }
    for (auto& v : vs) {
      std::cin >> v.x >> v.y;
    }
    std::priority_queue<Edge> edges;
    for (size_t i = 0; i < vs.size(); ++i) {
      for (size_t j = i + 1; j < vs.size(); ++j) {
        edges.push(Edge{dist(vs[i], vs[j]), i, j});
      }
    }
    double totalWeight = 0;
    nPoints--;
    while (nPoints > 0) {
      auto e = edges.top();
      edges.pop();
      int s1 = find(e.v1);
      int s2 = find(e.v2);
      if (s1 == s2) {
        continue;
      }
      nPoints--;
      ufs[s1] = s2;
      totalWeight += e.weight;
    }
    if (caseInd) {
      std::cout << std::endl;
    }
    std::cout << std::fixed << std::setprecision(2) << totalWeight << std::endl;
  }

  return 0;
}