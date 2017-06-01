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

class Node {
public:
  long long int data;
  int pos;
  bool highPart;

  Node(int data) : data(data), pos(0) {}
};

auto nodeGreater = [](Node *n1, Node *n2) {
  return n1->data > n2->data;
};

auto nodeLess = [](Node *n1, Node *n2) {
  return n1->data < n2->data;
};

class Solution {
public:
  template<typename T>
  void push(std::vector<Node *> &data, T cmp) {
    int i = data.size() - 1;
    while (i) {
      if (cmp(data[i], data[parent(i)])) {
        std::swap(data[i]->pos, data[parent(i)]->pos);
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
      } else {
        break;
      }
    }
  }

  template<typename T>
  void pop(std::vector<Node *> &data, T cmp) {
    int size = data.size() - 1;
    std::swap(data[0]->pos, data[size]->pos);
    std::swap(data[0], data[size]);
    int i = 0;
    while (i < size) {
      bool ok = true;
      if (lChild(i) < size) {
        ok = cmp(data[i], data[lChild(i)]);
      }
      if (ok && rChild(i) < size) {
        ok = cmp(data[i], data[rChild(i)]);
      }
      if (ok) {
        break;
      }
      int next = lChild(i);
      if (rChild(i) < size && cmp(data[rChild(i)], data[next])) {
        next = rChild(i);
      }
      std::swap(data[i]->pos, data[next]->pos);
      std::swap(data[i], data[next]);
      i = next;
    }
  }

  int parent(int i) {
    return (i - 1) / 2;
  }

  int lChild(int i) {
    return 2 * i + 1;
  }

  int rChild(int i) {
    return 2 * i + 2;
  }

  template<typename T>
  void adjust(std::vector<Node *> &data, int pos, Node *newNode, T cmp) {
    newNode->highPart = data[pos]->highPart;
    newNode->pos = pos;
    data[pos] = newNode;
    int i = pos;
    while (i && cmp(data[i], data[parent(i)])) {
      std::swap(data[i]->pos, data[parent(i)]->pos);
      std::swap(data[i], data[parent(i)]);
      i = parent(i);
    }
    i = pos;
    while (i < data.size()) {
      bool ok = true;
      if (lChild(i) < data.size()) {
        ok = cmp(data[i], data[lChild(i)]);
      }
      if (ok && rChild(i) < data.size()) {
        ok = cmp(data[i], data[rChild(i)]);
      }
      if (ok) {
        break;
      }
      int next = lChild(i);
      if (rChild(i) < data.size() && cmp(data[rChild(i)], data[next])) {
        next = rChild(i);
      }
      std::swap(data[i]->pos, data[next]->pos);
      std::swap(data[i], data[next]);
      i = next;
    }
  }

  std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
    if (k == 1) {
      return std::vector<double>{nums.begin(), nums.end()};
    }
    std::vector<Node *> seq;
    for (auto n : nums) {
      seq.push_back(new Node(n));
    }
    std::vector<Node *> seq_(seq.begin(), seq.begin() + k);
    std::sort(seq_.begin(), seq_.end(), nodeGreater);
    int m = k / 2;
    std::vector<Node *> highPart(seq_.begin(), seq_.begin() + m);
    std::vector<Node *> lowPart(seq_.begin() + m, seq_.begin() + k);
    std::make_heap(highPart.begin(), highPart.end(), nodeGreater);
    for (int i = 0; i < highPart.size(); ++i) {
      highPart[i]->pos = i;
      highPart[i]->highPart = true;
    }

    std::make_heap(lowPart.begin(), lowPart.end(), nodeLess);
    for (int i = 0; i < lowPart.size(); ++i) {
      lowPart[i]->pos = i;
      lowPart[i]->highPart = false;
    }
    std::vector<double> res;
    int sPos = 0;
    while (true) {
      if (highPart[0]->data < lowPart[0]->data) {
        pop(highPart, nodeLess);
        pop(lowPart, nodeGreater);
        std::swap(highPart.back(), lowPart.back());
        highPart.back()->pos = highPart.size() - 1;
        highPart.back()->highPart = true;
        lowPart.back()->pos = lowPart.size() - 1;
        lowPart.back()->highPart = false;
        push(highPart, nodeLess);
        push(lowPart, nodeGreater);
      }
      if (highPart.size() == lowPart.size()) {
        res.push_back((highPart[0]->data + lowPart[0]->data) / 2.0);
      } else if (highPart.size() == lowPart.size() + 1) {
        res.push_back(highPart[0]->data);
      } else if (highPart.size() + 1 == lowPart.size()) {
        res.push_back(lowPart[0]->data);
      }
      if (k == seq.size()) {
        break;
      }
      if (seq[sPos]->highPart) {
        adjust(highPart, seq[sPos]->pos, seq[k], nodeLess);
      } else {
        adjust(lowPart, seq[sPos]->pos, seq[k], nodeGreater);
      }
      sPos++;
      k++;
    }
    return res;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::vector<int> nums{7,0,3,9,9,9,1,7,2,3};
  auto res = s.medianSlidingWindow(nums, 6);
  for (auto m : res) {
    std::cout << m << " ";
  }

  return 0;
}