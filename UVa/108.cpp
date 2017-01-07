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

constexpr int MAX_N = 105;
int map[MAX_N][MAX_N];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> map[i][j];
            map[i][j] += map[i - 1][j];
        }
    }
    int maxSum = map[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int temp = 0;
            for (int k = 1; k <= n; ++k) {
                if (temp >= 0) {
                    temp += map[j][k] - map[i - 1][k];
                } else {
                    temp = map[j][k] - map[i - 1][k];
                }
                maxSum = std::max(maxSum, temp);
            }
        }
    }
    std::cout << maxSum << std::endl;
    return 0;
}