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

int coins[] = {1, 5, 10, 25, 50};
int D[8000][5];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n = 7500;
    for (int i = 0; i < 5; ++i) {
        D[0][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k <= j; ++k) {
                if (i - coins[k] >= 0) {
                    D[i][j] += D[i - coins[k]][k];
                }
            }
        }
    }
    while (std::cin >> n) {
        std::cout << D[n][4] << std::endl;
    }

    return 0;
}