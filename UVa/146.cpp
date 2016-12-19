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

int main() {
    while (true) {
        std::string str;
        std::cin >> str;
        if (*str.begin() == '#') {
            break;
        }
        if (std::next_permutation(str.begin(), str.end())) {
            std::cout << str << std::endl;
        } else {
            std::cout << "No Successor" << std::endl;
        }
    }
    return 0;
}
