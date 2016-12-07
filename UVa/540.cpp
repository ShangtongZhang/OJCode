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

class TeamQueue {
public:
    static constexpr int MAX_ELEMENTS = 1e6;
    static constexpr int MAX_TEAMS = 1000;
    std::list<int> queue;
    std::vector<int> teamTable;
    std::vector<std::list<int>::iterator> nodeTable;
    
    TeamQueue() :
    teamTable(MAX_ELEMENTS, 0),
    nodeTable(MAX_TEAMS, queue.end()) {
        
    }
    
    void enqueue(int elem) {
        int team = teamTable[elem];
        auto& pos = nodeTable[team];
        if (pos == queue.end()) {
            pos = queue.insert(pos, elem);
        } else {
            pos = queue.insert(std::next(pos), elem);
        }
    }
    
    int dequeue() {
        auto pos = queue.begin();
        int elem = *pos;
        auto next = std::next(pos);
        if (next == queue.end() || teamTable[*pos] != teamTable[*next]) {
            nodeTable[teamTable[*pos]] = queue.end();
        }
        queue.erase(pos);
        return elem;
    }
    
    void print() {
        std::cout << "Q:";
        for (auto it = queue.begin(); it != queue.end(); ++it) {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
    }
    
};

int main() {
    int caseIndex = 0;
    while (true) {
        int nTeams = 0;
        std::cin >> nTeams;
        if (nTeams == 0) {
            break;
        }
        caseIndex++;
        auto tq = TeamQueue();
        int teamIndex = 0;
        while (nTeams--) {
            int nElems = 0;
            std::cin >> nElems;
            int elem = 0;
            while (nElems--) {
                std::cin >> elem;
                tq.teamTable[elem] = teamIndex;
            }
            teamIndex++;
        }
        std::cout << "Scenario #" << caseIndex << std::endl;
        std::string cmd;
        int elem = 0;
        int cmdIndex = 0;
        while (true) {
            cmdIndex++;
            std::cin >> cmd;
            if (cmd[0] == 'E') {
                std::cin >> elem;
                tq.enqueue(elem);
            } else if (cmd[0] == 'D') {
                std::cout << tq.dequeue() << std::endl;
            } else {
                break;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
