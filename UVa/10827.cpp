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

constexpr int MAX_N = 160;
int map[MAX_N][MAX_N];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> map[i][j];
                map[i + n][j] = map[i][j];
            }
        }
        for (int i = 1; i <= 2 * n; ++i) {
            for (int j = 0; j < n; ++j) {
                map[i][j] += map[i - 1][j];
            }
        }
        int maxSum = map[1][1];
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= i + n - 1; ++j) {
                std::vector<int> row(2 * n);
                for (int k = 0; k < n; ++k) {
                    row[k] = row[k + n] = map[j][k] - map[i - 1][k];
                }
                std::vector<int> rowSum(2 * n + 1);
                for (int k = 1; k < (int)rowSum.size(); ++k) {
                    rowSum[k] = rowSum[k - 1] + row[k - 1];
                }
                for (int l = 1; l <= n; ++l) {
                    for (int r = l; r <= l + n - 1; ++r) {
                        maxSum = std::max(maxSum, rowSum[r] - rowSum[l - 1]);
                    }
                }
            }
        }
        std::cout << maxSum << std::endl;
    }
    return 0;
}