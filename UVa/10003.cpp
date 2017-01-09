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

int D[200][200];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    while (true) {
        int l;
        std::cin >> l;
        if (!l) {
            break;
        }
        std::memset(D, 0, sizeof(D));
        int nSeg;
        std::cin >> nSeg;
        std::vector<int> pos(nSeg + 1);
        pos.front() = 0;
        for (auto it = std::next(pos.begin()); it != pos.end(); ++it) {
            std::cin >> *it;
        }
        pos.push_back(l);
        for (int s = 2; s <= nSeg + 1; ++s) {
            for (int i = 0; i + s < (int)pos.size(); ++i) {
                int minCost = 0x7fffffff;
                for (int j = 1; j < s; ++j) {
                    minCost = std::min(minCost, D[i][i + j] + D[i + j][i + s]);
                }
                D[i][i + s] = minCost + pos[i + s] - pos[i];
            }
        }
        std::cout << "The minimum cutting is " << D[0][nSeg + 1] << "." << std::endl;

    }
    return 0;
}