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

constexpr int MAX_N = 755;
int N;

class Vertex {
public:
  int x;
  int y;
};

class Edge {
public:
  int v1;
  int v2;
  double weight;
};

double dist(const Vertex& v1, const Vertex&v2) {
  double dx = v1.x - v2.x;
  double dy = v1.y - v2.y;
  return std::sqrt(dx * dx + dy * dy);
}


int ufs[MAX_N];
int find(int i) {
  if (ufs[i] == i) {
    return i;
  }
  int p = find(ufs[i]);
  ufs[i] = p;
  return p;
}
bool completed() {
  int p = find(0);
  for (int i = 1; i < N; ++i) {
    if (find(i) != p) {
      return false;
    }
  }
  return true;
}

bool connected[MAX_N][MAX_N];

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  while (std::cin >> N) {
    for (int i = 0; i < N; ++i) {
      ufs[i] = i;
    }
    std::memset(connected, 0, sizeof(connected));
    std::vector<Vertex> vs(N);
    for (auto& v : vs) {
      std::cin >> v.x >> v.y;
    }
    int E;
    std::cin >> E;
    while (E--) {
      int v1, v2;
      std::cin >> v1 >> v2;
      v1--;
      v2--;
      ufs[find(v1)] = find(v2);
      connected[v1][v2] = connected[v2][v1]= true;
    }
    std::vector<Edge> es;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (!connected[i][j]) {
          es.emplace_back(Edge{i, j, dist(vs[i], vs[j])});
        }
      }
    }
    std::sort(es.begin(), es.end(), [](const Edge& e1, const Edge& e2) {
      return e1.weight > e2.weight;
    });
    double totalWeight = 0;
    while (!completed()) {
      auto& e = es.back();
      int s1 = find(e.v1);
      int s2 = find(e.v2);
      if (s1 != s2) {
        totalWeight += e.weight;
        ufs[s1] = s2;
      }
      es.pop_back();
    }
    std::cout << std::fixed << std::setprecision(2) << totalWeight << std::endl;
  }

  return 0;
}