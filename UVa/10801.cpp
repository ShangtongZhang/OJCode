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

constexpr int MAX_V = 505;
constexpr int MAX_N = 6;
constexpr int INF = std::numeric_limits<int>::max();
int dist[MAX_V];
bool exist[MAX_V];
bool inQueue[MAX_V];
int interval[MAX_N];
int N, K;
std::vector<std::vector<int>> map;

int find(int src) {
  std::fill(dist, dist + MAX_V, INF);
  std::memset(inQueue, 0, sizeof(inQueue));
  dist[src] = 0;
  std::queue<int> info;
  info.push(src);
  inQueue[src] = true;
  while (!info.empty()) {
    int node = info.front();
    info.pop();
    inQueue[node] = false;
    int ele = node / 100;
    int floor = node % 100;
    for (auto nextNode : map[ele]) {
      int f = nextNode % 100;
      if (f != floor) {
        int nextNode = ele * 100 + f;
        int cost = std::abs(f - floor) * interval[ele];
        if (dist[nextNode] > dist[node] + cost) {
          dist[nextNode] = dist[node] + cost;
          if (!inQueue[nextNode]) {
            info.push(nextNode);
            inQueue[nextNode] = true;
          }
        }
      }
    }
    for (int nextEle = 0; nextEle < N; ++nextEle) {
      if (nextEle != ele) {
        int nextNode = nextEle * 100 + floor;
        if (!exist[nextNode]) {
          continue;
        }
        int cost = 60;
        if (dist[nextNode] > dist[node] + cost) {
          dist[nextNode] = dist[node] + cost;
          if (!inQueue[nextNode]) {
            info.push(nextNode);
            inQueue[nextNode] = true;
          }
        }
      }
    }
  }
  int minDist = INF;
  for (int ele = 0; ele < N; ++ele) {
    minDist = std::min(minDist, dist[ele * 100 + K]);
  }
  return minDist;
}

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  while (std::cin >> N >> K) {
    map.clear();
    map.resize(N);
    std::memset(exist, 0, sizeof(exist));
    for (int i = 0; i < N; ++i) {
      std::cin >> interval[i];
    }
    std::string line;
    std::getline(std::cin, line);
    for (int i = 0; i < N; ++i) {
      std::getline(std::cin, line);
      std::stringstream ss(line);
      int floor;
      while (ss >> floor) {
        int node = 100 * i + floor;
        exist[node] = true;
        map[i].push_back(100 * i + floor);
      }
    }
    int minCost = INF;
    for (int ele = 0; ele < N; ++ele) {
      if (!map[ele].empty() && !(map[ele].front() % 100)) {
        minCost = std::min(minCost, find(ele * 100));
      }
    }
    if (minCost < INF) {
      std::cout << minCost << std::endl;
    } else {
      std::cout << "IMPOSSIBLE" << std::endl;
    }
  }

  return 0;
}