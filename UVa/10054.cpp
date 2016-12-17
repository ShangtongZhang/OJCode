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

constexpr int MAX_SIZE = 50;
int map[MAX_SIZE][MAX_SIZE];
int degree[MAX_SIZE];
bool visited[MAX_SIZE];

int main() {
    int nCase;
    std::cin >> nCase;
    int ind = 0;
    while (nCase--) {
        ind++;
        if (ind > 1) {
            std::cout << std::endl;
        }
        std::cout << "Case #" << ind << std::endl;
        std::memset(map, 0, sizeof(map));
        std::memset(degree, 0, sizeof(degree));
        std::memset(visited, 0, sizeof(visited));
        std::vector<std::vector<int>> edges(MAX_SIZE);
        int nEdge;
        std::cin >> nEdge;
        int nEdge_ = nEdge;
        int u = 0, v = 0;
        while (nEdge_--) {
            std::cin >> u >> v;
            u -= 1;
            v -= 1;
            map[u][v] += 1;
            map[v][u] += 1;
            degree[u] += 1;
            degree[v] += 1;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        int start = u;
        bool eulerCycle = true;
        for (int u = 0; u < MAX_SIZE; ++u) {
            if (degree[u] % 2) {
                eulerCycle = false;
                break;
            }
        }
        if (eulerCycle) {
            std::queue<int> path;
            path.push(u);
            while (!path.empty()) {
                int node = path.front();
                path.pop();
                visited[node] = true;
                for (int u = 0; u < MAX_SIZE; ++u) {
                    if (!visited[u] && map[node][u] > 0) {
                        path.push(u);
                    }
                }
            }
            for (int i = 0; i < MAX_SIZE; ++i) {
                if (!visited[i] && degree[i]) {
                    eulerCycle = false;
                    break;
                }
            }
        }
        if (eulerCycle) {
            std::list<int> path;
            path.push_back(start);
            auto it = path.begin();
            while (true) {
                while (true) {
                    if (edges[*it].empty()) {
                        break;
                    }
                    int u = *it;
                    int v = *edges[*it].begin();
                    path.insert(std::next(it), v);
                    edges[u].erase(edges[u].begin());
                    edges[v].erase(std::find(edges[v].begin(), edges[v].end(), u));
                    it++;
                }
                if (path.size() == nEdge + 1) {
                    break;
                }
                it = path.begin();
                while (edges[*it].empty()) {
                    ++it;
                }
            }
            for (auto it = path.begin(); it != std::prev(path.end()); ++it) {
                std::cout << *it + 1 << ' ' << *std::next(it) + 1 << std::endl;
            }
        } else {
            std::cout << "some beads may be lost" << std::endl;
        }
    }
    return 0;
}
