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

constexpr double INF = std::numeric_limits<double>::max();

class Point {
public:
    double x;
    double y;
};

double dist(Point& p1, Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

double solve(std::vector<Point>::iterator left, std::vector<Point>::iterator right) {
    if (right == left + 1) {
        return INF;
    }
    if (right == left + 2) {
        return dist(*left, *std::next(left));
    }
    auto mid = left + (right - left) / 2;
    double minDist = std::min(solve(left, mid), solve(mid, right));
    std::vector<Point> candidates;
    for (auto it = left; it < right; ++it) {
        if (std::abs(it->x - mid->x) <= minDist) {
            candidates.push_back(*it);
        }
    }
//    auto l = mid;
//    while (l >= left && mid->x - l->x <= minDist) {
//        l--;
//    }
//    if (mid->x - l->x > minDist) {
//        l++;
//    }
//    auto r = mid;
//    while (r < right && r->x - mid->x <= minDist) {
//        r++;
//    }
    std::sort(candidates.begin(), candidates.end(), [](Point& p1, Point& p2) {
        return p1.y < p2.y;
    });
    for (auto i = candidates.begin(); i < candidates.end(); ++i) {
        for (auto j = std::next(i); j < candidates.end(); ++j) {
            if (j->y - i->y > minDist) {
                break;
            }
            minDist = std::min(minDist, dist(*i, *j));
        }
    }
    return minDist;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n;
    while (true) {
        std::cin >> n;
        if (!n) {
            break;
        }
        std::vector<Point> points(n);
        for (auto& p : points) {
            std::cin >> p.x >> p.y;
        }
        std::sort(points.begin(), points.end(), [](Point& p1, Point& p2) {
            return p1.x < p2.x;
        });
        double d = solve(points.begin(), points.end());
        if (d >= 10000) {
            std::cout << "INFINITY" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(4) << d << std::endl;
        }
    }
    return 0;
}
