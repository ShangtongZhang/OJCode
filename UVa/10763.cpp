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
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        int paired = 0;
        int u, v;
        std::unordered_map<int, std::unordered_multiset<int>> dest;
        for (int i = 0; i < n; ++i) {
            std::cin >> u >> v;
            auto itV = dest.find(v);
            if (itV == dest.end() || itV->second.find(u) == itV->second.end()) {
                auto itU = dest.find(u);
                if (itU == dest.end()) {
                    itU = dest.insert(std::make_pair(u, std::unordered_multiset<int>())).first;
                }
                itU->second.insert(v);
                continue;
            }
            itV->second.erase(itV->second.find(u));
            paired += 2;
        }
        std::cout << (paired == n ? "YES" : "NO") << std::endl;
    }
    
    return 0;
}
