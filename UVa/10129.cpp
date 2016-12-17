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

int map[26][26];
int outDegree[26];
int inDegree[26];
bool visited[26];

int main() {
    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        std::memset(map, 0, sizeof(map));
        std::memset(outDegree, 0, sizeof(outDegree));
        std::memset(inDegree, 0, sizeof(inDegree));
        std::memset(visited, 0, sizeof(visited));
        int nWords;
        std::cin >> nWords;
        std::string word;
        int u, v;
        while (nWords--) {
            std::cin >> word;
            u = *word.begin() - 'a';
            v = *word.rbegin() - 'a';
            map[u][v] += 1;
            outDegree[u] += 1;
            inDegree[v] += 1;
        }
        bool flag1 = false;
        bool flag2 = false;
        bool eulerPath = true;
        for (int i = 0; i < 26; ++i) {
            if (outDegree[i] == inDegree[i]) {
                continue;
            }
            if (outDegree[i] == inDegree[i] + 1 && !flag1) {
                flag1 = true;
                continue;
            }
            if (outDegree[i] + 1 == inDegree[i] && !flag2) {
                flag2 = true;
                continue;
            }
            eulerPath = false;
            break;
        }
        eulerPath = eulerPath && (flag1 == flag2);
        std::queue<int> path;
        path.push(u);
        while (!path.empty()) {
            int node = path.front();
            path.pop();
            visited[node] = true;
            for (int v = 0; v < 26; ++v) {
                if ((map[node][v] > 0 || map[v][node] > 0) && !visited[v]) {
                    path.push(v);
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (!visited[i] && (outDegree[i] > 0 || inDegree[i] > 0)) {
                eulerPath = false;
                break;
            }
        }
        if (!eulerPath) {
            std::cout << "The door cannot be opened." << std::endl;
        } else {
            std::cout << "Ordering is possible." << std::endl;
        }
    }
    return 0;
}
