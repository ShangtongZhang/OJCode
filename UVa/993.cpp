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
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int n;
        std::cin >> n;
        std::vector<int> digits;
        int i = 9;
        while (n != 1 && i > 1) {
            if (n % i == 0) {
                n /= i;
                digits.push_back(i);
            } else {
                i--;
            }
        }
        if (n == 1 && digits.empty()) {
            digits.push_back(1);
        }
        if (n > 1) {
            std::cout << -1 << std::endl;
        } else {
            for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
                std::cout << *it;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
