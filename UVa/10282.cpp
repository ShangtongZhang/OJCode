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

int main() {
    std::string line;
    std::unordered_map<std::string, std::string> vocab;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::stringstream ss(line);
        std::string w1, w2;
        ss >> w1 >> w2;
        vocab[w2] = w1;
    }
    while (std::getline(std::cin, line)) {
        auto it = vocab.find(line);
        std::cout << (it == vocab.end() ? "eh" : it->second) << std::endl;
    }
    return 0;
}
