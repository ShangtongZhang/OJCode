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

constexpr int MAX_SIZE = 36;
bool station[MAX_SIZE];
bool visited[MAX_SIZE];

void solve(std::vector<std::vector<int>>& map, size_t cur, int stations, int& minStations, std::vector<bool>& hasStation, std::vector<bool>& subMap) {
    while (cur < map.size() && !subMap[cur]) {
        cur++;
    }
    if (cur == map.size()) {
        for (size_t i = 0; i < hasStation.size(); ++i) {
            if (!hasStation[i] && subMap[i]) {
                return;
            }
        }
        minStations = std::min(stations, minStations);
        return;
    }
    if (stations > minStations) {
        return;
    }
    bool skip = true;
    bool safeSkip = map[cur].size();
    for (auto v : map[cur]) {
        if (!station[v]) {
            safeSkip = false;
        }
        if (v < cur) {
            if (!hasStation[v] && *map[v].rbegin() <= cur) {
                skip = false;
            }
        }
    }
    std::vector<bool> hasStation_;
    if (skip) {
        hasStation_ = hasStation;
        solve(map, cur + 1, stations, minStations, hasStation_, subMap);
    }
    if (!safeSkip) {
        hasStation_ = hasStation;
        hasStation_[cur] = true;
        station[cur] = true;
        for (auto v : map[cur]) {
            hasStation_[v] = true;
        }
        solve(map, cur + 1, stations + 1, minStations, hasStation_, subMap);
        station[cur] = false;
    }

}

int main() {
//            std::ifstream in("in.txt");
//            std::cin.rdbuf(in.rdbuf());
//            std::ofstream out("out.txt");
//            std::cout.rdbuf(out.rdbuf());
    while (true) {
        int N, M;
        std::cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        std::vector<std::vector<int>> map(N);
        std::vector<bool> hasStation(N);
        std::memset(visited, 0, sizeof(visited));
        std::memset(station, 0, sizeof(station));
        int u, v;
        while (M--) {
            std::cin >> u >> v;
            u--;
            v--;
            map[u].push_back(v);
            map[v].push_back(u);
        }
        for (auto& u : map) {
            std::sort(u.begin(), u.end());
        }
        int total = 0;
        for (int i = 0; i < N; ++i) {
            if (visited[i]) {
                continue;
            }
            std::queue<int> path;
            std::vector<bool> subMap(N);
            path.push(i);
            while (!path.empty()) {
                int u = path.front();
                visited[u] = true;
                subMap[u] = true;
                path.pop();
                for (auto v : map[u]) {
                    if (!visited[v]) {
                        path.push(v);
                    }
                }
            }
            int minStations = MAX_SIZE;
            solve(map, 0, 0, minStations, hasStation, subMap);
            total += minStations;
        }
        std::cout << total << std::endl;
    }
    return 0;
}
