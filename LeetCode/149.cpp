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

struct Point {
  int x;
  int y;

  Point() : x(0), y(0) {}

  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
  int maxPoints(std::vector<Point> &points) {
    if (points.empty()) {
      return 0;
    }
    if (points.size() == 1) {
      return 1;
    }
    int res = -1;
    for (size_t i = 0; i < points.size(); ++i) {
      auto cmp = [&points, i](const Point &p1, const Point &p2) {
        auto &p0 = points[i];
        if ((p1.x > p0.x && p2.x > p0.x) || (p1.x < p0.x && p2.x < p0.x)) {
          return (long double)(p1.y - p0.y) * (long double)(p2.x - p0.x) < (long double)(p2.y - p0.y) * (long double)(p1.x - p0.x);
        } else {
          return (long double)(p1.y - p0.y) * (long double)(p2.x - p0.x) > (long double)(p2.y - p0.y) * (long double)(p1.x - p0.x);
        }
      };
      std::map<Point, int, decltype(cmp)> ks(cmp);
      int maxPoints = -1;
      int vertical = 0;
      int samePoints = 0;
      for (size_t j = i + 1; j < points.size(); ++j) {
        if (points[j].x == points[i].x) {
          if (points[j].y == points[i].y) {
            samePoints++;
          } else {
            vertical++;
          }
          continue;
        }
        if (ks.count(points[j]) > 0) {
          ks[points[j]] += 1;
        } else {
          ks[points[j]] = 1;
        }
        maxPoints = std::max(maxPoints, ks[points[j]]);
      }
      maxPoints = std::max(maxPoints, vertical);
      res = std::max(res, maxPoints + samePoints);
    }
    return res + 1;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  Solution s;
  std::vector<Point> points{{0,0},{94911151,94911150},{94911152,94911151}};
  std::cout << s.maxPoints(points) << std::endl;

  return 0;
}