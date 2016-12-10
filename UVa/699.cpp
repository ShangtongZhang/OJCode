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

constexpr int offset = 100;

bool buildTree(std::stringstream& ss, int col, std::vector<int>& leaves) {
    int root = 0;
    if (!(ss >> root)) {
        ss.clear();
        std::string line;
        std::getline(std::cin, line);
        ss << line;
        ss >> root;
    }
    if (root == -1) {
        return false;
    }
    int& leaf = leaves[col + offset];
    leaf = leaf == -1 ? root : leaf + root;
    buildTree(ss, col - 1, leaves);
    buildTree(ss, col + 1, leaves);
    return true;
}

int main() {
//    std::ifstream in("data.txt");
//    std::cin.rdbuf(in.rdbuf());
    std::stringstream ss;
    std::string line;
    std::vector<int> leaves(offset * 2, -1);
    int nCase = 0;
    while (std::getline(std::cin, line)) {
        nCase++;
        ss.clear();
        ss << line;
        for (auto& i : leaves) {
            i = -1;
        }
        if (buildTree(ss, 0, leaves)) {
            std::cout << "Case " << nCase << ":" << std::endl;
            line.clear();
            for (auto& i : leaves) {
                if (i != -1) {
                    line += std::to_string(i) + ' ';
                }
            }
            line.erase(std::prev(line.end()));
            std::cout << line << std::endl << std::endl;
        } else {
            break;
        }
    }
    return 0;
}
