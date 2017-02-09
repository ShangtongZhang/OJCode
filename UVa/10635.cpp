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

constexpr int MAX = 250 * 250 + 5;
int N, P, Q;
int D[MAX];
int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    int nCase;
    std::cin >> nCase;
    for (int caseInd = 1; caseInd <= nCase; ++caseInd) {
        std::cin >> N >> P >> Q;
        P++;
        Q++;
        std::memset(D, 0, sizeof(D));
        int pos = 1;
        int tmp;
        while (P--) {
            std::cin >> tmp;
            D[tmp] = pos;
            pos++;
        }
        std::vector<int> indices;
        while (Q--) {
            std::cin >> tmp;
            if (D[tmp]) {
                indices.push_back(D[tmp]);
            }
        }
        std::vector<int> path;
        for (int ind : indices) {
            if (path.empty() || ind > path.back()) {
                path.push_back(ind);
            }
            auto it = std::upper_bound(path.begin(), path.end(), ind);
            if (it != path.end()) {
                *it = ind;
            }
        }
        std::cout << "Case " << caseInd << ": " << path.size() << std::endl;
    }
    return 0;
}