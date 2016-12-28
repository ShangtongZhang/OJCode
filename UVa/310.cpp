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

std::string r1, r2, w, target;

std::string extend(std::string& oldStr) {
    std::string newStr;
    for (auto it = oldStr.begin(); it != oldStr.end(); ++it) {
        if (*it == 'a') {
            newStr += r1;
        }
        if (*it == 'b') {
            newStr += r2;
        }
    }
    return newStr;
}

int hash(std::string& str) {
    int v = 0;
    int base = 1;
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        v += (*it - 'a') * base;
        base *= 2;
    }
    return v;
}

bool visited[1 << 17];
int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    while (std::getline(std::cin, r1)) {
        std::memset(visited, 0, sizeof(visited));
        std::getline(std::cin, r2);
        std::getline(std::cin, w);
        std::getline(std::cin, target);
        while (w.size() < target.size()) {
            w = extend(w);
        }
        std::queue<std::string> path;
        for (size_t i = 0; i <= w.size() - target.size(); ++i) {
            path.push(w.substr(i, target.size()));
        }
        bool flag = false;
        while (!path.empty()) {
            auto u = path.front();
            path.pop();
            if (u == target) {
                flag = true;
                break;
            }
            auto h = hash(u);
            if (visited[h]) {
                continue;
            }
            visited[h] = true;
            auto v = extend(u);
            for (size_t i = 0; i <= v.size() - target.size(); ++i) {
                path.push(v.substr(i, target.size()));
            }
        }
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}
