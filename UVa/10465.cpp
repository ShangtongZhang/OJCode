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

constexpr int MAX = 10005;
constexpr int INF = 0x7fffffff;
int D[MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int m, n, t;
    while (std::cin >> m >> n >> t) {
        if (m > n) {
            std::swap(m, n);
        }
        std::memset(D, 0, sizeof(D));
        for (int i = 1; i <= t; ++i) {
            if (i >= n) {
                if (D[i - n] == 0 && D[i - m] == 0) {
                    D[i] = i == n ? 1 : 0;
                } else {
                    D[i] = std::max(D[i - n], D[i - m]) + 1;
                }
            } else if (i >= m) {
                if (D[i - m] == 0) {
                    D[i] = i == m ? 1 : 0;
                } else {
                    D[i] = D[i - m] + 1;
                }
            } else {
                D[i] = 0;
            }
        }
        int i = t;
        while (i) {
            if (D[i] > 0) {
                std::cout << D[i];
                if (i < t) {
                    std::cout << ' ' << t - i;
                }
                std::cout << std::endl;
                break;
            }
            i--;
        }
        if (i == 0) {
            std::cout << 0 << ' ' << t << std::endl;
        }
    }
    return 0;
}