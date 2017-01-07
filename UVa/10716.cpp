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

size_t solve(std::string& str) {
    if (str.size() == 1 || str.size() == 0) {
        return 0;
    }
    if (str.size() == 2) {
        if (str.front() == str.back()) {
            return 0;
        } else {
            return -1;
        }
    }
    for (size_t i = 0; i < str.size(); ++i) {
        size_t pos = str.find_last_of(str[i]);
        if (pos != std::string::npos && pos != i) {
            size_t count = i + str.size() - 1 - pos;
            str.erase(pos, 1);
            str.erase(i, 1);
            size_t r = solve(str);
            if (r != -1) {
                return count + r;
            } else {
                return -1;
            }
        }
    }
    return -1;
}

int main() {
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::string str;
        std::cin >> str;
        size_t r = solve(str);
        if (r != -1) {
            std::cout << r << std::endl;
        } else {
            std::cout << "Impossible" << std::endl;
        }
    }
    return 0;
}
