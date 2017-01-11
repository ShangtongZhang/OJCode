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

bool D[105][50005];

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
        std::vector<int> coins(n);
        for (auto& coin : coins) {
            std::cin >> coin;
        }
        std::memset(D, 0, sizeof(D));
        D[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 50000; ++j) {
                if (D[i][j]) {
                    if (j + coins[i] <= 50000) {
                        D[i + 1][j + coins[i]] = true;
                    }
                    D[i + 1][std::abs(j - coins[i])] = true;
                }
            }
        }
        int diff = 0;
        while (diff <= 500) {
            if (D[n][diff]) {
                break;
            }
            diff++;
        }
        std::cout << diff << std::endl;
    }
    return 0;
}