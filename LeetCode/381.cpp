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
#include "random"

class RandomizedCollection {
public:
  std::vector<int> data;
  std::unordered_map<int, std::vector<int>> info;
  int pos;
  /** Initialize your data structure here. */
  RandomizedCollection() {
    pos = 0;
    data.push_back(0);
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val) {
    data[pos] = val;
    auto it = info.find(val);
    bool exist = it == info.end() || it->second.empty();
    info[val].push_back(pos++);
    if (pos >= data.size()) {
      data.push_back(0);
    }
    return exist;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val) {
    auto it = info.find(val);
    if (it == info.end() || it->second.empty()) {
      return false;
    }
    int pos_ = it->second.back();
    it->second.pop_back();
    data[pos_] = data[--pos];
    it = info.find(data[pos_]);
    for (auto it_ = it->second.begin(); it_ != it->second.end(); ++it_) {
      if (*it_ == pos) {
        *it_  = pos_;
        break;
      }
    }
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, pos - 1);
    return data[dis(gen)];
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  return 0;
}