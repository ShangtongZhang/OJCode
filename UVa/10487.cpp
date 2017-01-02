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
    int ind = 0;
    while (true) {
        int n;
        std::cin >> n;
        ind++;
        if (!n) {
            break;
        }
        std::vector<int> nums(n);
        for (auto& num : nums) {
            std::cin >> num;
        }
        std::vector<int> sums;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            for (auto it2 = std::next(it); it2 != nums.end(); ++it2) {
                sums.push_back(*it + *it2);
            }
        }
        std::sort(sums.begin(), sums.end());
        std::cout << "Case " << ind << ":" << std::endl;
        int m, target, closest;
        std::cin >> m;
        while (m--) {
            std::cin >> target;
            auto it = std::lower_bound(sums.begin(), sums.end(), target);
            if (it == sums.end()) {
                closest = sums.back();
            } else if (it == sums.begin()) {
                closest = *it;
            } else {
                if (*it - target > target - *std::prev(it)) {
                    closest = *std::prev(it);
                } else {
                    closest = *it;
                }
            }
            std::cout << "Closest sum to " << target << " is " << closest << "." << std::endl;
        }
    }
    return 0;
}
