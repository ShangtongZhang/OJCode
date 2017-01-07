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

std::vector<int> solve(std::vector<int> nums) {
    if (nums.size() < 3) {
        return nums;
    }
    if (nums.size() == 3) {
        std::swap(nums[0], nums[1]);
        return nums;
    }
    std::vector<int> left, right;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i % 2) {
            right.push_back(nums[i]);
        } else {
            left.push_back(nums[i]);
        }
    }
    left = solve(left);
    right = solve(right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main() {
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        std::vector<int> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back(i);
        }
        nums = solve(nums);
        std::cout << n << ":";
        for (auto& num : nums) {
            std::cout << ' ' << num;
        }
        std::cout << std::endl;
    }
    return 0;
}
