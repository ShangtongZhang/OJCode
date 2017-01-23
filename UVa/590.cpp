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

constexpr int MAX_N = 15;
constexpr int MAX_K = 1005;
constexpr int INF = 0x7fffffff;

int map[MAX_N][MAX_N];
int D[MAX_K][MAX_N];
std::vector<std::vector<int>> flights;

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n, k;
    int caseInd = 0;
    while (true) {
        std::cin >> n >> k;
        if (!n && !k) {
            break;
        }
        D[0][1] = 0;
        for (int i = 2; i <= n; ++i) {
            D[0][i] = INF;
        }
        caseInd++;
        flights.clear();
        int index = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j == i) {
                    continue;
                }
                int p;
                std::cin >> p;
                std::vector<int> fs(p);
                for (auto& f: fs) {
                    std::cin >> f;
                }
                map[i][j] = index;
                index++;
                flights.push_back(std::move(fs));
            }
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                D[i][j] = INF;
                for (int m = 1; m <= n; ++m) {
                    if (m == j) {
                        continue;
                    }
                    auto& fs = flights[map[m][j]];
                    int cost = fs[(i - 1) % fs.size()];
                    if (cost > 0 && D[i - 1][m] < INF) {
                        D[i][j] = std::min(D[i][j], D[i - 1][m] + cost);
                    }
                }
            }
        }
        std::cout << "Scenario #" << caseInd << std::endl;
        if (D[k][n] == INF) {
            std::cout << "No flight possible." << std::endl;
        } else {
            std::cout << "The best flight costs " << D[k][n] << "." << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}