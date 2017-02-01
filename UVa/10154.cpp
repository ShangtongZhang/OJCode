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

constexpr int MAX = 5610;
constexpr int INF = 0x3f3f3f3f;
int D[MAX][MAX];

class Node {
public:
    int w;
    int s;
};

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int W, S;
    std::vector<Node> turtles;
    while (std::cin >> W >> S) {
        turtles.push_back(Node{W, S});
    }
    std::sort(turtles.begin(), turtles.end(), [](Node& n1, Node& n2) {
        return n1.s < n2.s;
    });
    int len = turtles.size();
    for (int j = 1; j <= len; ++j) {
        D[0][j] = INF;
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            D[i][j] = D[i - 1][j];
            if (turtles[i - 1].s >= turtles[i - 1].w + D[i - 1][j - 1]) {
                D[i][j] = std::min(D[i][j], D[i - 1][j - 1] + turtles[i - 1].w);
            }
        }
    }
    int j = len;
    while (D[len][j] >= INF) {
        j--;
    }
    std::cout << j << std::endl;
    return 0;
}