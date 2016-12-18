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

constexpr int MAX_SIZE = 100;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];

void DFS(int u, int n, std::vector<int>& path) {
    visited[u] = true;
    for (int v = 0; v < n; ++v) {
        if (map[u][v] && !visited[v]) {
            DFS(v, n, path);
        }
    }
    path.push_back(u);
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    while (true) {
        int n, m;
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        std::memset(map, 0, sizeof(map));
        std::memset(visited, 0, sizeof(visited));
        int u, v;
        while (m--) {
            std::cin >> u >> v;
            u -= 1;
            v -= 1;
            map[v][u] = 1;
        }
        std::vector<int> path;
        for (int u = 0; u < n; ++u) {
            if (!visited[u]) {
                DFS(u, n, path);
            }
        }
        for (auto it = path.begin(); it != path.end(); ++it) {
            if (it != path.begin()) {
                std::cout << ' ';
            }
            std::cout << *it + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}
