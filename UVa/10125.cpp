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
#include "unordered_map"
#include "unordered_set"

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    while (true) {
        std::vector<int> S;
        std::unordered_set<int> ht;
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        int tmp;
        while (n--) {
            std::cin >> tmp;
            S.push_back(tmp);
            ht.insert(tmp);
        }
        std::sort(S.begin(), S.end());
        bool flag = false;
        for (auto itD = std::prev(S.end()); itD >= S.begin(); --itD) {
            for (auto itA = S.begin(); itA < S.end(); ++itA) {
                for (auto itB = std::next(itA); itB < S.end(); ++itB) {
                    int c = *itD - *itA - *itB;
                    if (c <= *itB) {
                        break;
                    }
                    if (c != *itD && ht.count(c)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                std::cout << *itD << std::endl;
                break;
            }
        }
        if (!flag) {
            std::cout << "no solution" << std::endl;
        }
    }
    return 0;
}
