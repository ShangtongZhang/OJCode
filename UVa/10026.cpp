#include "iostream"
#include "vector"
#include "math.h"
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

class Node {
public:
    int T;
    int S;
    int ind;
};

int main() {
    std::ifstream in("in.txt");
    std::cin.rdbuf(in.rdbuf());
    std::ofstream out("out.txt");
    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    bool first = true;
    while (nCase--) {
        if (!first) {
            std::cout << std::endl;
        }
        first = false;
        int nLine, T, S;
        std::cin >> nLine;
        std::vector<Node> jobs;
        for (int i = 1; i <= nLine; ++i) {
            std::cin >> T >> S;
            jobs.push_back(Node{T, S, i});
        }
        std::sort(jobs.begin(), jobs.end(), [](Node& n1, Node& n2) {
            int f1 = n2.S * n1.T;
            int f2 = n1.S * n2.T;
            if (f1 != f2) {
                return f1 < f2;
            }
            return n1.ind < n2.ind;
        });
        for (auto it = jobs.begin(); it != jobs.end(); ++it) {
            if (it != jobs.begin()) {
                std::cout << ' ' << it->ind;
            } else {
                std::cout << it->ind;
            }
//            std::cout << it->ind << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
