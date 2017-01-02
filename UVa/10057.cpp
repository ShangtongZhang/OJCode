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

    int n;
    while (std::cin >> n) {
        std::vector<int> nums(n);
        for (auto& num : nums) {
            std::cin >> num;
        }
        int minA, count = 0, totalA;
        std::sort(nums.begin(), nums.end());
        if (n % 2 == 0) {
            int l = n / 2 - 1;
            int r = n / 2;
            minA = nums[l];
            if (nums[l] != nums[r]) {
                totalA = nums[r] - nums[l] + 1;
            } else {
                totalA = 1;
            }
            int val = nums[l];
            while (nums[l] == val && l >= 0) {
                count++;
                l--;
            }
            val = nums[r];
            while (nums[r] == val && r < nums.size()) {
                count++;
                r++;
            }
        } else {
            int p = n / 2;
            minA = nums[p];
            totalA = 1;
            while (nums[p] == minA && p >= 0) {
                count++;
                p--;
            }
            p = n / 2 + 1;
            while (nums[p] == minA && p < nums.size()) {
                count++;
                p++;
            }
        }
        std::cout << minA << ' ' << count << ' ' << totalA << std::endl;
    }
    return 0;
}
