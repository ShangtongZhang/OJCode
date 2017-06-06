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

class SummaryRanges {
public:
  /** Initialize your data structure here. */
  std::list<Interval> intervals;
  SummaryRanges() {

  }

  void addNum(int val) {
    if (intervals.empty()) {
      intervals.push_back(Interval(val, val));
      return;
    }
    auto it = std::upper_bound(intervals.begin(), intervals.end(), Interval(val, val),
                               [](const Interval& i1, const Interval& i2) { return i1.start < i2.start; });
    if (it == intervals.end()) {
      if (intervals.back().end < val) {
        if (intervals.back().end + 1 == val) {
          intervals.back().end = val;
        } else {
          intervals.push_back(Interval(val, val));
        }
      }
    } else {
      if (it == intervals.begin()) {
        if (it->start == val + 1) {
          it->start = val;
        } else {
          intervals.insert(it, Interval(val, val));
        }
      } else {
        auto prev_it = std::prev(it);
        if (val > prev_it->end) {
          if (val == prev_it->end + 1 && val == it->start - 1) {
            prev_it->end = it->end;
            intervals.erase(it);
          } else if (val == it->start - 1) {
            it->start = val;
          } else if (val == prev_it->end + 1) {
            prev_it->end = val;
          } else {
            intervals.insert(it, Interval(val, val));
          }
        }
      }
    }
  }

  std::vector<Interval> getIntervals() {
    return {intervals.begin(), intervals.end()};
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}