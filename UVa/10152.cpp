#include "iostream"
#include "vector"
#include "math.h"
#include "map"
#include "string"
#include "list"
#include "set"
#include "algorithm"

int main() {
    int nCases = 0;
    std::cin >> nCases;
    while (nCases--) {
        int nTurtles = 0;
        std::cin >> nTurtles;
        std::list<std::string> turtles;
        std::list<std::string> order;
        std::string tmp;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        for (int i = 0; i < nTurtles; ++i) {
            std::getline(std::cin, tmp);
            turtles.push_front(tmp);
        }
        for (int i = 0; i < nTurtles; ++i) {
            std::getline(std::cin, tmp);
            order.push_front(tmp);
        }
        auto itOrder = order.begin();
        std::set<std::string> freeTurtles;
        while (true) {
            auto itTurtles = turtles.begin();
            while (itOrder != order.end() && *itOrder == *itTurtles) {
                itOrder++;
                itTurtles++;
            }
            if (itOrder == order.end()) {
                break;
            }
            itTurtles = turtles.erase(turtles.begin(), itTurtles);
            itOrder = order.erase(order.begin(), itOrder);
            auto pos = freeTurtles.find(*itOrder);
            if (pos != freeTurtles.end()) {
                std::cout << *pos << std::endl;
                turtles.push_back(*pos);
                freeTurtles.erase(pos);
            }
            auto sep = std::find(turtles.begin(), turtles.end(), *itOrder);
            freeTurtles.insert(turtles.begin(), sep);
            turtles.erase(turtles.begin(), sep);
        }
        std::cout << std::endl;
    }
}
