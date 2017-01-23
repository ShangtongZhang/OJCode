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

constexpr int MAX = (1 << 12) + 5;
int count[MAX];

int solve(std::bitset<12>& map) {
    if (count[map.to_ulong()] > -1) {
        return count[map.to_ulong()];
    }
    int minCount = map.count();
    for (int i = 0; i <= 10; ++i) {
        if (map[i] && map[i + 1]) {
            if (i - 1 >= 0 && !map[i - 1]) {
                map[i - 1] = true;
                map[i + 1] = false;
                map[i] = false;
                minCount = std::min(solve(map), minCount);
                map[i] = true;
                map[i - 1] = false;
                map[i + 1] = true;
            }
            if (i + 2 <= 11 && !map[i + 2]) {
                map[i] = false;
                map[i + 2] = true;
                map[i + 1] = false;
                minCount = std::min(solve(map), minCount);
                map[i + 1] = true;
                map[i] = true;
                map[i + 2] = false;
            }
        }
    }
    count[map.to_ulong()] = minCount;
    return minCount;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    char tmp;
    while (nCase--) {
        std::bitset<12> map;
        std::memset(count, -1, sizeof(count));
        for (int i = 0; i < (int)map.size(); ++i) {
            std::cin >> tmp;
            if (tmp == '-') {
                map[i] = false;
            } else {
                map[i] = true;
            }
        }
        std::cout << solve(map) << std::endl;
    }
    return 0;
}