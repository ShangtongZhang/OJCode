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
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        std::vector<std::string> nums(n);
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            std::cin >> *it;
        }
        auto cmp = [](const std::string& s1, const std::string& s2) {
            auto it1 = s1.begin();
            auto it2 = s2.begin();
            while (true) {
                if (it1 == s1.end() && it2 == s2.end()) {
                    return true;
                }
                if (it1 == s1.end()) {
                    it1 = s1.begin();
                }
                if (it2 == s2.end()) {
                    it2 = s2.begin();
                }
                if (*it1 < *it2) {
                    return true;
                }
                if (*it1 > *it2) {
                    return false;
                }
                it1++;
                it2++;
            }
            return it2 == s2.end();
        };
        std::sort(nums.begin(), nums.end(), cmp);
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            std::cout << *it;
        }
        std::cout << std::endl;
    }
    return 0;
}
