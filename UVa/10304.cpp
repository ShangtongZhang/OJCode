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

constexpr int MAX = 255;
int D[MAX][MAX];
int S[MAX][MAX];
int F[MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n;
    while (std::cin >> n) {
        for (int i = 1; i <= n; ++i) {
            std::cin >> F[i];
            S[i][i] = F[i];
        }
        for (int l = 1; l < n; ++l) {
            for (int i = 1; i + l <= n; ++i) {
                int j = i + l;
                S[i][j] = S[i][i] + S[i + 1][j];
            }
        }
        for (int l = 1; l < n; ++l) {
            for (int i = 1; i + l <= n; ++i) {
                int j = i + l;
                D[i][j] = 0x7fffffff;
                for (int k = i; k <= j; ++k) {
                    D[i][j] = std::min(D[i][j], D[i][k - 1] + D[k + 1][j] + S[i][k - 1] + S[k + 1][j]);
                }
            }
        }
        std::cout << D[1][n] << std::endl;
    }

    return 0;
}