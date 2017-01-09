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

using Node = std::vector<int>;
bool contained(Node& n1, Node& n2) {
    auto it1 = n1.begin();
    auto it2 = n2.begin();
    while (it1 != n1.end()) {
        if (*it1 >= *it2) {
            return false;
        }
        it1++;
        it2++;
    }
    return true;
}

std::vector<int> maxLength;
std::vector<int> next;

int solve(int u, std::vector<std::vector<int>>& edges) {
    if (maxLength[u] != -1) {
        return maxLength[u];
    }
    int nextV = -1;
    int maxDist = 0;
    for (auto v : edges[u]) {
        int dist = solve(v, edges);
        if (dist > maxDist) {
            maxDist = dist;
            nextV = v;
        }
    }
    maxDist++;
    maxLength[u] = maxDist;
    next[u] = nextV;
    return maxDist;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int k, n;
    while (std::cin >> k >> n) {
        std::vector<Node> nodes(k);
        for (auto& node : nodes) {
            node.resize(n);
            for (auto& d : node) {
                std::cin >> d;
            }
            std::sort(node.begin(), node.end());
        }
        std::vector<std::vector<int>> edges(k);
        for (size_t i = 0; i < nodes.size(); ++i) {
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                if (contained(nodes[i], nodes[j])) {
                    edges[i].push_back(j);
                } else if (contained(nodes[j], nodes[i])) {
                    edges[j].push_back(i);
                }
            }
        }
        maxLength.clear();
        maxLength.resize(k, -1);
        next.clear();
        next.resize(k, -1);
        int maxL = 0;
        int cur = -1;
        for (int u = 0; u < k; ++u) {
            int dist = solve(u, edges);
            if (dist > maxL) {
                maxL = dist;
                cur = u;
            }
        }
        std::cout << maxL << std::endl;
        std::cout << cur + 1;
        cur = next[cur];
        while (cur != -1) {
            std::cout << ' ' << cur + 1;
            cur = next[cur];
        }
        std::cout << std::endl;
    }
    return 0;
}