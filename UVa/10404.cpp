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

int D[1000005];

int solve(int i, std::vector<int>& nums) {
    if (D[i]) {
        return D[i];
    }
    int win = 2;
    for (auto num : nums) {
        if (i - num > 0) {
            if (solve(i - num, nums) == 2) {
                win = 1;
                break;
            }
        }
    }
    D[i] = win;
    return win;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n;
    while (std::cin >> n) {
        int m;
        std::cin >> m;
        std::memset(D, 0, sizeof(D));
        std::vector<int> nums(m);
        for (auto& num : nums) {
            std::cin >> num;
            D[num] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            solve(i, nums);
        }
        std::cout << (solve(n, nums) == 1 ? "Stan wins" : "Ollie wins") << std::endl;
    }
    return 0;
}