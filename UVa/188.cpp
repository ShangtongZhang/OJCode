#include "iostream"
#include "vector"
#include "math.h"
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
constexpr int INF = 0x7FFFFFFF;

int toInt(std::string& str) {
    int base = 1;
    int v = 0;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        v += (*it - 'a' + 1) * base;
        base *= 32;
    }
    return v;
}

bool check(std::vector<int>& words, int C, int& nextC) {
    nextC = C + 1;
    std::vector<std::vector<int>> ht(words.size());
    bool flag = true;
    for (auto word : words) {
        int h = C / word % words.size();
        if (ht[h].empty()) {
            ht[h].push_back(word);
        } else {
            int w2 = ht[h].back();
            nextC = std::max(nextC, std::min((C / word + 1) * w2, (C / w2 + 1) * word));
            flag = false;
        }
    }
    return flag;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::vector<int> words;
        std::string word;
        int candidateC = INF;
        while (ss >> word) {
            int tmp = toInt(word);
            candidateC = std::min(tmp, candidateC);
            words.push_back(tmp);
        }
        int nextC;
        while (!check(words, candidateC, nextC)) {
            candidateC = nextC;
        }
        std::cout << line << std::endl << candidateC << std::endl << std::endl;
    }
    return 0;
}
