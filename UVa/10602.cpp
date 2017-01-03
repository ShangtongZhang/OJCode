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

int keep(std::string& s1, std::string& s2, int& dist) {
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    while (it1 != s1.end() && it2 != s2.end() && *it1 == *it2) {
        it1++;
        it2++;
    }
    dist = s2.end() - it2;
    return it1 - s1.begin();
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int nWords;
        std::cin >> nWords;
        std::list<std::string> words(nWords);
        std::vector<std::string> out;
        for (auto& word : words) {
            std::cin >> word;
        }
        out.push_back(std::move(words.front()));
        int nPress = int(out.front().size());
        words.pop_front();
        while (!words.empty()) {
            auto selected = words.end();
            int minKeep = -0x7FFFFFFF;
            int dist;
            for (auto it = words.begin(); it != words.end(); ++it) {
                int dist_;
                int k = keep(out.back(), *it, dist_);
                if (k > minKeep) {
                    minKeep = k;
                    selected = it;
                    dist = dist_;
                }
//                if (d == minDist) {
//                    if (it->size() < selected->size()) {
//                        selected = it;
//                    }
//                }
            }
            out.push_back(std::move(*selected));
            nPress += dist;
            words.erase(selected);
        }
        std::cout << nPress << std::endl;
        for (auto& word : out) {
            std::cout << word << std::endl;
        }
    }
    return 0;
}
