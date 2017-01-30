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

constexpr int MAX = 65;
long long int D[MAX][MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::string line;
        std::cin >> line;
        int len = (int)line.size();
        for (int i = 1; i <= len; ++i) {
            D[i][i] = 1;
        }
        for (int l = 1; l < len; ++l) {
            for (int i = 1; i <= len - l; ++i) {
                int j = i + l;
                D[i][j] = D[i][j - 1] + D[i + 1][j] - D[i + 1][j - 1];
                if (line[i - 1] == line[j - 1]) {
                    D[i][j] += D[i + 1][j - 1] + 1;
                }
            }
        }
        std::cout << D[1][len] << std::endl;
    }

    return 0;
}