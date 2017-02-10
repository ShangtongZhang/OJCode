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

constexpr int MAX = 1005;
constexpr int INF = 0x7fffffff;
int L, C;
int DI(int t) {
    if (!t) {
        return 0;
    }
    if (t <= 10) {
        return -C;
    }
    return (t - 10) * (t - 10);
}

int topics[MAX];
int D[MAX][MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int caseInd = 0;
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        caseInd++;
        std::cin >> L >> C;
        for (int i = 1; i <= n; ++i) {
            std::cin >> topics[i];
        }
        for (int i = 1; i <= n; ++i) {
            D[i][0] = INF;
            D[0][i] = INF;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                D[i][j] = INF;
                int k = 0;
                int sum = 0;
                while (true) {
                    if (k == i) {
                        break;
                    }
                    sum += topics[i - k];
                    if (sum > L) {
                        break;
                    }
                    k++;
                    if (D[i - k][j - 1] != INF) {
                        D[i][j] = std::min(D[i][j], D[i - k][j - 1] + DI(L - sum));
                    }
                }
            }
        }
        int j = 0;
        while (D[n][j] >= INF) {
            j++;
        }
        if (caseInd > 1) {
            std::cout << std::endl;
        }
        std::cout << "Case " << caseInd << ":" << std::endl;
        std::cout << "Minimum number of lectures: " << j << std::endl;
        std::cout << "Total dissatisfaction index: " << D[n][j] << std::endl;
    }

    return 0;
}