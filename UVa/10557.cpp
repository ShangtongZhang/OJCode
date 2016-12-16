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

int main() {
//    std::ifstream in("data.txt");
//    std::cin.rdbuf(in.rdbuf());
    int rooms = 0;
    while (true) {
        std::cin >> rooms;
        if (rooms == -1) {
            break;
        }
        std::vector<int> energy(rooms);
        std::vector<std::vector<int>> map(rooms);
        std::vector<std::vector<int>> invMap(rooms);
        std::vector<bool> candidate(rooms, false);
        int tmp;
        int room;
        int startRoom = 0;
        int finishRoom = rooms - 1;
        for (int i = 0; i < rooms; ++i) {
            std::cin >> tmp;
            energy[i] = tmp;
            std::cin >> tmp;
            while (tmp--) {
                std::cin >> room;
                map[i].push_back(room - 1);
                invMap[room - 1].push_back(i);
            }
        }
        
        
        std::queue<int> possibleRooms;
        possibleRooms.push(finishRoom);
        while (!possibleRooms.empty()) {
            int room = possibleRooms.front();
            possibleRooms.pop();
            candidate[room] = true;
            for (auto r : invMap[room]) {
                if (!candidate[r]) {
                    possibleRooms.push(r);
                }
            }
        }
        
        int inf = rooms * 100 * 10;
        std::vector<int> distance(rooms, -inf);
        distance[startRoom] = 0;
        for (int i  = 0; i < rooms - 1; ++i) {
            for (int u = 0; u < rooms; ++u) {
                for (auto v : map[u]) {
                    if (distance[u] != -inf) {
                        int newDist = distance[u] + energy[v];
                        if (newDist > -100 && newDist > distance[v]) {
                            distance[v] = newDist;
                        }
                    }
                }
            }
        }
        bool reachable = false;
        if (distance[finishRoom] != -inf) {
            reachable = true;
        } else {
            for (int u = 0; u < rooms - 1; ++u) {
                for (auto v : map[u]) {
                    if (distance[u] != -inf) {
                        int newDist = distance[u] + energy[v];
                        if (newDist > -100 && newDist > distance[v]) {
                            if (candidate[v]) {
                                reachable = true;
                            }
                        }
                    }
                }
            }
        }
        std::cout << (reachable ? "winnable" : "hopeless") << std::endl;
    }
    return 0;
}
