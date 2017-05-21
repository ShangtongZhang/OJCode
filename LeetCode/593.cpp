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
  using Point = std::vector<int>;
  bool validSquare(std::vector<int> &p1, std::vector<int> &p2, std::vector<int> &p3, std::vector<int> &p4) {
    std::vector<Point> points{p1, p2, p3, p4};
    std::vector<long long int> distances;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        distances.push_back(dist(points[i], points[j]));
      }
    }
    std::map<long long int, int> info;
    for (auto d : distances) {
      info[d] += 1;
    }
    if (info.size() != 2) {
      return false;
    }
    auto it1 = info.begin();
    auto it2 = std::next(it1);
    if (it1->first == 0 || it2->first == 0) {
      return false;
    }
    if ((it1->second == 4 && it2->second == 2) || (it1->second == 2 && it2->second == 4)) {
      return true;
    }
    return false;
  }

  long long int dist(const Point & p1, const Point & p2) {
    long long int dx = p1[0] - p2[0];
    long long int dy = p1[1] - p2[1];
    return dx * dx + dy * dy;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}