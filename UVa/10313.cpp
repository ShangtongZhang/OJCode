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

constexpr int MAX = 305;
long long int D[MAX][MAX][MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int N = 300;
    for (int j = 1; j <= N; ++j) {
        D[1][j][j] = 1;
        D[j][0][0] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int s = 0; s <= N; ++s) {
                D[i][j][s] = D[i - 1][j][s];
                if (s >= i) {
                    D[i][j][s] += D[i][j - 1][s - i];
                }
            }
        }
    }

    std::string line;
    while(std::getline(std::cin, line)) {
        std::stringstream ss;
        ss << line;
        std::vector<int> specs;
        int tmp;
        while (ss >> tmp) {
            specs.push_back(tmp);
        }
        if (specs.size() == 1) {
            specs.push_back(0);
            specs.push_back(N);
        } else if (specs.size() == 2) {
            specs.insert(std::prev(specs.end()), 0);
        }
        long long int sum = 0;
        for (int j = specs[1]; j <= std::min(specs[2], N); ++j) {
            sum += D[N][j][specs[0]];
        }
        std::cout << sum << std::endl;
    }

    return 0;
}