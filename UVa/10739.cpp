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
int D[MAX][MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    int nCase;
    std::cin >> nCase;
    for (int caseIndex = 1; caseIndex <= nCase; ++caseIndex) {
        std::string str;
        std::cin >> str;
        int len = (int)str.size();
        std::memset(D, 0, sizeof(D));
        for (int l = 1; l <= len; ++l) {
            for (int i = 0; i + l < len; ++i) {
                int j = i + l;
                D[i][j] = 0x7fffffff;
                if (str[i] == str[j]) {
                    D[i][j] = D[i + 1][j - 1];
                } else {
                    D[i][j] = std::min(D[i][j], D[i + 1][j - 1] + 1);
                    D[i][j] = std::min(D[i][j], D[i][j - 1] + 1);
                    D[i][j] = std::min(D[i][j], D[i + 1][j] + 1);
                }
            }
        }
        std::cout << "Case " << caseIndex << ": " << D[0][len - 1] << std::endl;
    }
    return 0;
}