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
  std::vector<std::vector<bool>> search(const std::string &word) {
    int len = word.size();
    std::vector<std::vector<bool>> D(len);
    for (auto &row : D) {
      row.resize(len);
    }
    for (int i = 0; i < word.size(); ++i) {
      D[i][i] = true;
    }
    for (int l = 2; l <= len; ++l) {
      for (int i = 0; i < len; ++i) {
        int j = i + l - 1;
        if (j >= len) {
          break;
        }
        if (word[i] != word[j]) {
          D[i][j] = false;
        } else {
          if (j == i + 1) {
            D[i][j] = true;
          } else {
            D[i][j] = D[i + 1][j - 1];
          }
        }
      }
    }
    return D;
  }

  std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words) {
    std::unordered_map<std::string, int> info;
    bool emptyWord = false;
    int emptyWordPos = -1;
    for (int i = 0; i < words.size(); ++i) {
      if (words[i].empty()) {
        emptyWord = true;
        emptyWordPos = i;
        continue;
      }
      info[words[i]] = i;
    }
    std::vector<std::vector<int>> res;
    for (int i = 0; i < words.size(); ++i) {
      auto &word = words[i];
      if (word.empty()) {
        continue;
      }
      auto D = search(word);
      if (D[0][word.size() - 1]) {
        if (emptyWord) {
          res.push_back(std::vector<int>{i, emptyWordPos});
          res.push_back(std::vector<int>{emptyWordPos, i});
        }
      } else {
        std::string padding = word;
        std::reverse(padding.begin(), padding.end());
        auto it = info.find(padding);
        if (it != info.end()) {
          res.push_back(std::vector<int>{i, it->second});
        }
      }
      for (int j = 0; j < word.size() - 1; ++j) {
        if (D[0][j]) {
          std::string padding = word.substr(j + 1);
          std::reverse(padding.begin(), padding.end());
          auto it = info.find(padding);
          if (it != info.end() && it->second != i) {
            res.push_back(std::vector<int>{it->second, i});
          }
        }
      }
      for (int j = word.size() - 1; j > 0; --j) {
        if (D[j][word.size() - 1]) {
          std::string padding = word.substr(0, j);
          std::reverse(padding.begin(), padding.end());
          auto it = info.find(padding);
          if (it != info.end() && it->second != i) {
            res.push_back(std::vector<int>{i, it->second});
          }
        }
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

  std::vector<std::string> words{"a","b","c","ab","ac","aa"};
//  std::vector<std::string> words{"a", "abc", "aba", ""};
  Solution s;
  auto res = s.palindromePairs(words);
  for (auto &v : res) {
    std::cout << v[0] << " " << v[1] << std::endl;
  }

  return 0;
}