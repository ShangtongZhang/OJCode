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

constexpr int INF = 0x7fffffff;
int D[41][301][301];

int value1[41];
int value2[41];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int m, S;
        std::cin >> m >> S;
        for (int i = 1; i <= m; ++i) {
            std::cin >> value1[i] >> value2[i];
        }
        int minCoins = INF;
        for (int x = 0; x <= S; ++x) {
            int y2 = S * S - x * x;
            int y = (int)std::sqrt(y2);
            if (y * y == y2) {
                for (int k = 1; k <= m; ++k) {
                    for (int i = 0; i <= x; ++i) {
                        for (int j = 0; j <= y; ++j) {
                            D[k][i][j] = D[k - 1][i][j];
                            int p = 1;
                            while (true) {
                                int iP = i - p * value1[k];
                                int jP = j - p * value2[k];
                                if (iP >= 0 && jP >= 0) {
                                    if (D[k - 1][iP][jP] > 0 || (iP == 0 && jP == 0)) {
                                        if (D[k][i][j] == 0) {
                                            D[k][i][j] = D[k - 1][iP][jP] + p;
                                        } else {
                                            D[k][i][j] = std::min(D[k][i][j], D[k - 1][iP][jP] + p);
                                        }
                                    }
                                    p++;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }
                if (D[m][x][y] > 0) {
                    minCoins = std::min(minCoins, D[m][x][y]);
                }
            }
        }
        if (minCoins < INF) {
            std::cout << minCoins << std::endl;
        } else {
            std::cout << "not possible" << std::endl;
        }
    }

    return 0;
}