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

int map[15][105];
int D[15][105];
int next[15][105];

int offset[] = {-1, 0, 1};
constexpr int INF = 0x7fffffff;

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int m, n;
    while (std::cin >> m >> n) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> map[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            D[i][n - 1] = map[i][n - 1];
            next[i][n - 1] = -1;
        }
        for (int j = n - 2; j >= 0; --j) {
            for (int i = 0; i < m; ++i) {
                int nextR = -1;
                int minCost = INF;
                for (int k = 0; k < 3; ++k) {
                    int nextRow = (i + m + offset[k]) % m;
                    int cost = D[nextRow][j + 1];
                    if (cost < minCost) {
                        minCost = cost;
                        nextR = nextRow;
                    } else if (cost == minCost) {
                        nextR = std::min(nextR, nextRow);
                    }
                }
                D[i][j] = minCost + map[i][j];
                next[i][j] = nextR;
            }
        }
        int startPos = -1;
        int minCost = INF;
        for (int i = 0; i < m; ++i) {
            if (D[i][0] < minCost) {
                minCost = D[i][0];
                startPos = i;
            }
        }
        int curCol = 0;
        while (curCol < n) {
            if (curCol > 0) {
                std::cout << ' ';
            }
            std::cout << startPos + 1;
            startPos = next[startPos][curCol];
            curCol++;
        }
        std::cout << std::endl;
        std::cout << minCost << std::endl;

    }
    return 0;
}