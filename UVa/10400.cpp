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

constexpr int limit = 32000;
bool flag[100][2 * limit + 1];

template <class IT>
bool check(IT cur, IT end, int target, std::list<char>& ops) {
    if (target < -limit || target > limit) {
        return false;
    }
    if (!flag[cur - end][target + limit]) {
        return false;
    }
    if (cur == end) {
        return *cur == target;
    }
    if (check(std::prev(cur), end, target - *cur, ops)) {
        ops.push_back('+');
        return true;
    }
    if (check(std::prev(cur), end, target + *cur, ops)) {
        ops.push_back('-');
        return true;
    }
    if (target % *cur == 0 && check(std::prev(cur), end, target / *cur, ops)) {
        ops.push_back('*');
        return true;
    }
    if (check(std::prev(cur), end, target * *cur, ops)) {
        ops.push_back('/');
        return true;
    }
    flag[cur - end][target + limit] = false;
    return false;
}

int main() {
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::memset(flag, 1, sizeof(flag));
        int nNum, target;
        std::cin >> nNum;
        std::vector<int> nums(nNum);
        for (auto& num : nums) {
            std::cin >> num;
        }
        std::cin >> target;
        std::list<char> ops;
        if (check(std::prev(nums.end()), nums.begin(), target, ops)) {
            auto itOp = ops.begin();
            auto itNum = nums.begin();
            std::cout << *itNum;
            itNum++;
            while (itOp != ops.end()) {
                std::cout << *itOp << *itNum;
                itOp++;
                itNum++;
            }
            std::cout << "=" << target << std::endl;
        } else {
            std::cout << "NO EXPRESSION" << std::endl;
        }
    }
    return 0;
}
