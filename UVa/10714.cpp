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
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int len, n;
        std::cin >> len >> n;
        std::vector<int> ants(n);
        for (auto& ant : ants) {
            std::cin >> ant;
        }
        std::sort(ants.begin(), ants.end());
        auto it = std::upper_bound(ants.begin(), ants.end(), len / 2);
        int minTime;
        if (it == ants.begin()) {
            minTime = len - *it;
        } else {
            minTime = std::max(len - *it, *std::prev(it));
        }
        int maxTime = std::max(len - ants.front(), ants.back());
        std::cout << minTime << ' ' << maxTime << std::endl;
    }
    return 0;
}
