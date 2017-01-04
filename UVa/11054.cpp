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

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        std::vector<int> inhs(n);
        long long int cost = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> inhs[i];
            if (i > 0) {
                cost += std::abs(inhs[i-1]);
                inhs[i] += inhs[i-1];
            }
        }
        std::cout << cost << std::endl;
    }
    return 0;
}
