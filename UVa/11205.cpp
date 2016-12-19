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

bool subset(int P, int nMasks, int cur, std::bitset<15>& map, const std::vector<std::bitset<15>>& symbols) {
    if (map.count() == nMasks) {
        std::set<int> flag;
        for (auto& symbol : symbols) {
            flag.insert((map | symbol).to_ulong());
        }
        if (flag.size() == symbols.size()) {
            return true;
        }
        return false;
    } else if (cur >= P) {
        return false;
    } else {
        map[cur] = true;
        if (subset(P, nMasks, cur + 1, map, symbols)) {
            return true;
        }
        map[cur] = false;
        return subset(P, nMasks, cur + 1, map, symbols);
    }
}

int main() {
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int P, N;
        int tmp;
        std::cin >> P >> N;
        std::vector<std::bitset<15>> symbols(N);
        for (auto& symbol : symbols) {
            for (int i = 0; i < P; ++i) {
                std::cin >> tmp;
                symbol[i] = tmp;
            }
        }
        for (int i = 0; i <= P; ++i) {
            std::bitset<15> map;
            if (subset(P, P - i, 0, map, symbols)) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}
