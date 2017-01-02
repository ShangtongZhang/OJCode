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
    std::string s, t;
    while (std::cin >> s >> t) {
        auto it = s.begin();
        auto it2 = t.begin();
        bool flag = true;
        while (it != s.end()) {
            while (it2 != t.end() && *it2 != *it) {
                it2++;
            }
            if (it2 == t.end()) {
                flag = false;
                break;
            }
            it2++;
            it++;
        }
        std::cout << (flag ? "Yes" : "No") << std::endl;
    }
    return 0;
}
