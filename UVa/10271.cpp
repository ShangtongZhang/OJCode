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

constexpr int MAX_N = 5005;
constexpr int MAX_K = 1005;
constexpr int INF = 0x3f3f3f3f;
int K, N;

int L[MAX_N];
int D[MAX_N][MAX_K];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::cin >> K >> N;
        K += 8;
        for (int i = N; i >= 1; --i) {
            std::cin >> L[i];
        }
        for (int j = 0; j <= K; ++j) {
            D[0][j] = INF;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= K; ++j) {
                if (i - 2 > 3 * (j - 1)) {
                    D[i][j] = std::min(D[i - 1][j], D[i - 2][j - 1] + (L[i] - L[i - 1]) * (L[i] - L[i - 1]));
                } else {
                    D[i][j] = D[i - 1][j];
                }
            }
        }
        std::cout << D[N][K] << std::endl;
    }

    return 0;
}