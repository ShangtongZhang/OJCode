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

constexpr int MAX_N = 1005;
int P[MAX_N];
int W[MAX_N];

int D[MAX_N][35];
int N;

int maxP(int maxW) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= maxW; ++j) {
            if (j >= W[i]) {
                D[i][j] = std::max(D[i - 1][j], D[i - 1][j - W[i]] + P[i]);
            } else {
                D[i][j] = D[i - 1][j];
            }
        }
    }
    return D[N][maxW];
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::cin >> N;
        for (int i = 1; i <= N; ++i) {
            std::cin >> P[i];
            std::cin >> W[i];
        }
        int G;
        std::cin >> G;
        int sum = 0;
        while (G--) {
            int maxW;
            std::cin >> maxW;
            sum += maxP(maxW);
        }
        std::cout << sum << std::endl;
    }
    return 0;
}