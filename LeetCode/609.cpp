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
  std::vector<std::vector<std::string>> findDuplicate(std::vector<std::string> &paths) {
    std::unordered_map<std::string, std::vector<std::string>> info;
    for (auto &path : paths) {
      std::stringstream ss(path);
      std::string dir;
      ss >> dir;
      std::string file;
      while (ss >> file) {
        int p1 = file.find('(');
        int p2 = file.find(')');
        std::string fullPath = dir + '/' + file.substr(0, p1);
        std::string content = file.substr(p1, p2 - p1);
        info[content].push_back(fullPath);
      }
    }
    std::vector<std::vector<std::string>> res;
    for (auto it = info.begin(); it != info.end(); ++it) {
      if (it->second.size() > 1) {
        res.push_back(std::move(it->second));
      }
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
  std::vector<std::string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
  auto res = s.findDuplicate(paths);
  for (auto& g : res) {
    for (auto& f : g) {
      std::cout << f << " ";
    }
    std::cout << std::endl;
  }


  return 0;
}