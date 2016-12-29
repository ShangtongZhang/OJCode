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

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    
    int n;
    std::cin >> n;
    int nCase = 0;
    while (n--) {
        nCase++;
        int s1, s2;
        std::vector<std::string> A, B;
        std::unordered_set<std::string> C;
        std::cin >> s1 >> s2;
        std::string tmp;
        std::getline(std::cin, tmp);
        while (s1--) {
            std::getline(std::cin, tmp);
            A.push_back(tmp);
        }
        while (s2--) {
            std::getline(std::cin, tmp);
            B.push_back(tmp);
        }
        for (auto itA = A.begin(); itA != A.end(); ++itA) {
            for (auto itB = B.begin(); itB != B.end(); ++itB) {
                C.insert(*itA + *itB);
            }
        }
        std::cout << "Case " << nCase << ": " << C.size() << std::endl;
    }
    return 0;
}
