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

constexpr int MAX = 105;

int R, C;
int map[MAX][MAX];
int len[MAX][MAX];

int solve(int i, int j) {
    if (len[i][j] > -1) {
        return len[i][j];
    }
    int l = 0;
    if (map[i - 1][j] < map[i][j]) {
        l = std::max(l, solve(i - 1, j));
    }
    if (map[i + 1][j] < map[i][j]) {
        l = std::max(l, solve(i + 1, j));
    }
    if (map[i][j - 1] < map[i][j]) {
        l = std::max(l, solve(i, j - 1));
    }
    if (map[i][j + 1] < map[i][j]) {
        l = std::max(l, solve(i, j + 1));
    }
    l++;
    len[i][j] = l;
    return l;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::string name;
        std::cin >> name >> R >> C;
        std::memset(len, -1, sizeof(len));
        std::memset(map, MAX, sizeof(map));
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                std::cin >> map[i][j];
            }
        }
        int maxL = -1;
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                maxL = std::max(solve(i, j), maxL);
            }
        }
        std::cout << name << ": " << maxL << std::endl;
    }
    return 0;
}