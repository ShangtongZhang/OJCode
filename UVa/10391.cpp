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
    std::string line;
    std::unordered_set<std::string> vocab;
    std::set<std::string> compuond;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        vocab.insert(line);
    }
    for (auto& word : vocab) {
        for (auto it = word.begin(); it != word.end(); ++it) {
            if (vocab.count(std::string(word.begin(), it)) && vocab.count(std::string(it, word.end()))) {
                compuond.insert(word);
                break;
            }
        }
    }
    for (auto& word : compuond) {
        std::cout << word << std::endl;
    }
    
    return 0;
}
