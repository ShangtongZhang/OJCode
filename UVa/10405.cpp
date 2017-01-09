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
int D[MAX_N][MAX_N];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    std::string s1, s2;
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
        std::memset(D, 0, sizeof(D));
        for (size_t i = 1; i <= s1.size(); ++i) {
            for (size_t j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    D[i][j] = D[i - 1][j - 1] + 1;
                } else {
                    D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);
                }
            }
        }
        std::cout << D[s1.size()][s2.size()] << std::endl;
    }
    return 0;
}