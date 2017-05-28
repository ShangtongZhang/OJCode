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

struct Interval {
  int start;
  int end;

  Interval() : start(0), end(0) {}

  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval) {
    if (intervals.empty()) {
      return {newInterval};
    }
    std::vector<Interval> res;
    int i = 0;
    while (i < intervals.size()) {
      if (intervals[i].end < newInterval.start) {
        res.push_back(intervals[i]);
      } else {
        int newStart = std::min(intervals[i].start, newInterval.start);
        while (i < intervals.size() && intervals[i].end < newInterval.end) { ++i; }
        if (i == intervals.size()) {
          res.push_back(Interval(newStart, newInterval.end));
          return res;
        }
        if (newInterval.end < intervals[i].start) {
          res.push_back(Interval(newStart, newInterval.end));
        } else {
          res.push_back(Interval(newStart, intervals[i].end));
          i++;
        }
        while (i < intervals.size()) {
          res.push_back(intervals[i++]);
        }
        return res;
      }
      ++i;
    }
    res.push_back(newInterval);
    return res;
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}