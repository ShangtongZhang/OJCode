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

bool dfs(std::map<int, int>& parts, std::map<int, int>::reverse_iterator it, int length, int targetLength, int nParts) {
    if (nParts == 0) {
        return length == 0;
    }
    while (true) {
        if (it == parts.rend()) {
            break;
        }
//    for (; it != parts.end(); ++it) {
        if (it->second == 0) {
            it++;
            continue;
        }
        bool flag;
        if (length + it->first < targetLength) {
            it->second -= 1;
            flag = dfs(parts, it, length + it->first, targetLength, nParts - 1);
            it->second += 1;
        } else if (length + it->first == targetLength) {
            it->second -= 1;
            flag = dfs(parts, parts.rbegin(), 0, targetLength, nParts - 1);
            it->second += 1;
            if (!flag) {
                return false;
            }
        }
        if (flag) {
            return flag;
        }
        if (length == 0) {
            break;
        }
        it++;
    }
    return false;
}

int main() {
    while (true) {
        int n = 0;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::map<int, int> parts;
        int tmp = 0;
        int n_ = n;
        int totalLength = 0;
        while (n_--) {
            std::cin >> tmp;
            if (parts.find(tmp) != parts.end()) {
                parts[tmp] += 1;
            } else {
                parts[tmp] = 1;
            }
            totalLength += tmp;
        }
        int targetLength = 0;
        for (targetLength = 1; targetLength <= totalLength; ++targetLength) {
            if (totalLength % targetLength == 0 && targetLength >= parts.rbegin()->first) {
                if (dfs(parts, parts.rbegin(), 0, targetLength, n)) {
                    break;
                }
            }
        }
        std::cout << targetLength << std::endl;
    }
    return 0;
}
