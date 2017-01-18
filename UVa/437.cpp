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

constexpr int MAX_N = 185;

class Node {
public:
    int b1;
    int b2;
    int h;
    int index;
};

namespace std {
    template <>
    class hash<Node> {
    public:
        std::size_t operator() (const Node& n) const {
            return n.b1 + n.b2 + n.h;
        }
    };

    template <>
    class equal_to<Node> {
    public:
        std::size_t operator() (const Node& n1, const Node& n2) const {
            return n1.b1 == n2.b1 && n1.b2 == n2.b2 && n1.h == n2.h;
        }
    };
}


template <class T>
int solve(int u, std::vector<int>& D, T& edge, T& cost) {
    if (D[u] > -1) {
        return D[u];
    }
    int c = 0;
    for (int i = 0; i < edge[u].size(); ++i) {
        c = std::max(c, cost[u][i] + solve(edge[u][i], D, edge, cost));
    }
    D[u] = c;
    return c;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int caseInd = 0;
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        caseInd++;
        std::vector<int> dim(3);
        std::vector<int> initalCost(MAX_N);
        std::vector<int> D(MAX_N, -1);
        std::vector<std::vector<int>> edge(MAX_N);
        std::vector<std::vector<int>> cost(MAX_N);
        std::unordered_set<Node> nodes;
        int nodeInd = 0;
        while (n--) {
            for (auto& d : dim) {
                std::cin >> d;
            }
            std::sort(dim.begin(), dim.end());
            do {
                Node node{dim[0], dim[1], dim[2], nodeInd};
                if (nodes.find(node) == nodes.end()) {
                    nodes.insert(node);
                    initalCost[nodeInd] = node.h;
                    for (auto& node_ : nodes) {
                        if (node_.b1 < node.b1 && node_.b2 < node.b2) {
                            edge[node.index].push_back(node_.index);
                            cost[node.index].push_back(node_.h);
                        }
                        if (node.b1 < node_.b1 && node.b2 < node_.b2) {
                            edge[node_.index].push_back(node.index);
                            cost[node_.index].push_back(node.h);
                        }
                    }
                    nodeInd++;
                }
            } while (std::next_permutation(dim.begin(), dim.end()));
        }
        int maxCost = -1;
        for (int i = 0; i < nodeInd; ++i) {
            maxCost = std::max(maxCost, initalCost[i] + solve(i, D, edge, cost));
        }
        std::cout << "Case " << caseInd << ": maximum height = " << maxCost << std::endl;
    }
    return 0;
}