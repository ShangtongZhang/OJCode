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


bool dfs(std::vector<std::string>& frags, std::vector<bool>& visited, std::string& target) {
    bool allVisited = true;
    for (auto it = visited.begin(); it != visited.end(); ++it) {
        if (!*it) {
            allVisited = false;
            break;
        }
    }
    if (allVisited) {
        return true;
    }
    int i = 0;
    while (i < frags.size()) {
        if (visited[i]) {
            i++;
            continue;
        }
        int j = (int)frags.size() - 1;
        while (j >= 0) {
            if (visited[j]) {
                j--;
                continue;
            }
            visited[i] = true;
            visited[j] = true;
            if (target.empty()) {
                target = frags[i] + frags[j];
                if (dfs(frags, visited, target)) {
                    return true;
                }
                target = frags[j] + frags[i];
                if (dfs(frags, visited, target)) {
                    return true;
                }
            } else {
                if (frags[i] + frags[j] == target) {
                    if (dfs(frags, visited, target)) {
                        return true;
                    }
                } else if (frags[j] + frags[i] == target) {
                    if (dfs(frags, visited, target)) {
                        return true;
                    }
                } else {
                    visited[i] = false;
                    visited[j] = false;
                }
            }
            j--;
        }
        i++;
    }
    return false;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n;
    std::cin >> n;
    std::string line;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    int ind = 0;
    while (ind < n) {
        std::vector<std::string> frags;
        while (!std::cin.eof()) {
            std::getline(std::cin, line);
            if (line.empty()) {
                break;
            }
            frags.push_back(line);
        }
        std::sort(frags.begin(), frags.end(), [](std::string& s1, std::string& s2) {
            return s1.size() < s2.size();
        });
        std::vector<bool> visited(frags.size(), false);
        std::string target;
        dfs(frags, visited, target);
        if (ind > 0) {
            std::cout << std::endl;
        }
        std::cout << target << std::endl;
        ind++;
    }
    return 0;
}
