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

class StringIterator {
public:
  std::stringstream ss;
  char data;
  int count;
  bool end;

  StringIterator(std::string compressedString) : ss(compressedString) {
    end = compressedString.empty();
    if (!end) {
      ss >> data;
      ss >> count;
    }
  }

  char next() {
    if (end) { return ' '; }
    count -= 1;
    char c = data;
    if (count == 0) {
      if (!ss.eof()) {
        ss >> data;
        ss >> count;
      } else {
        end = true;
      }
    }
    return c;
  }

  bool hasNext() {
    return !end;
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());

  StringIterator iterator("L1e2t1C1o1d1e1");
  std::cout << iterator.next();
  std::cout << iterator.next();
  std::cout << iterator.next();
  std::cout << iterator.next();
  std::cout << iterator.next();
  std::cout << iterator.next();
  std::cout << iterator.next();
  std::cout << iterator.hasNext();
  std::cout << iterator.next();
  std::cout << iterator.hasNext();
  std::cout << iterator.next();


  return 0;
}