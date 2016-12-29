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

bool solve(std::string& str, std::vector<int>& mod, int cur, int n, int m) {
    if (cur > m) {
        return true;
    }
    for (int i = (cur == 1 ? 1 : 0); i <= 9; ++i) {
        if (cur >= n && (mod[cur] * (10 % cur) + i % cur) % cur) {
            continue;
        }
        str += '0' + i;
        std::vector<int> newMod(mod.size());
        for (size_t j = 1; j < newMod.size(); ++j) {
            newMod[j] = (mod[j] * (10 % j) + i % j) % j;
        }
        if (solve(str, newMod, cur + 1, n, m)) {
            return true;
        }
        str.pop_back();
    }
    return false;
}

int main() {
    int nCase;
    std::cin >> nCase;
    for (int ind = 1; ind <= nCase; ++ind) {
        int n, m;
        std::cin >> n >> m;
        std::string num;
        std::vector<int> mod(30, 0);
        bool flag = solve(num, mod, 1, n, m);
        std::cout << "Case " << ind << ": " << (flag ? num : "-1") << std::endl;
    }
    return 0;
}
