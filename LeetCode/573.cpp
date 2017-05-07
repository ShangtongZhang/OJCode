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
  int minDistance(int height, int width,
                  std::vector<int> &tree,
                  std::vector<int> &squirrel,
                  std::vector<std::vector<int>> &nuts) {
    int INF = 0x7f7f7f7f;
    int steps = 0;
    int maxDec = -INF;
    int desiredNut = 0;
    for (int i = 0; i < nuts.size(); ++i) {
      int newDist = dist(squirrel, nuts[i]) + dist(nuts[i], tree);
      int originalDist = dist(nuts[i], tree) * 2;
      steps += originalDist;
      int decreasedDist = originalDist - newDist;
      if (decreasedDist > maxDec) {
        maxDec = decreasedDist;
//        desiredNut = i;
      }
    }
    steps -= maxDec;
//    steps += dist(squirrel, nuts[desiredNut]) + dist(nuts[desiredNut], tree);
//    nuts.erase(nuts.begin() + desiredNut);
//    for (auto& nut : nuts) {
//      steps += dist(tree, nut) * 2;
//    }
    return steps;
  }

  int dist(std::vector<int> &p1, std::vector<int> &p2) {
    return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
  }

};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  std::vector<int> tree{2, 2};
  std::vector<int> squirrel{4, 4};
  std::vector<std::vector<int>> nuts;
  nuts.emplace_back(std::vector<int>{3, 0});
  nuts.emplace_back(std::vector<int>{2, 5});
  Solution s;
  std::cout << s.minDistance(5, 7, tree, squirrel, nuts) << std::endl;

  return 0;
}