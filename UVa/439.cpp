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
    std::string line;
    std::stringstream ss;
    int x1, y1, x2, y2;
    char tmp;
    bool map[8][8];
    std::vector<int> offsetX = {-2, -1, 1, 2, 2, 1, -1, -2};
    std::vector<int> offsetY = {1, 2, 2, 1, -1, -2, -2, -1};
    while (std::getline(std::cin, line)) {
        ss.clear();
        ss << line;
        ss >> tmp;
        x1 = tmp - 'a';
        ss >> tmp;
        y1 = tmp - '1';
        ss >> tmp;
        x2 = tmp - 'a';
        ss >> tmp;
        y2 = tmp - '1';
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                map[i][j] = false;
            }
        }
        std::queue<int> x;
        std::queue<int> y;
        std::queue<int> step;
        x.push(x1);
        y.push(y1);
        step.push(0);
        int minStep = 0;
        while (!x.empty()) {
            int oldX = x.front();
            int oldY = y.front();
            int step_ = step.front();
            x.pop();
            y.pop();
            step.pop();
            map[oldX][oldY] = true;
            if (oldX == x2 && oldY == y2) {
                minStep = step_;
                break;
            }
            for (int i = 0; i < 8; ++i) {
                int newX = oldX + offsetX[i];
                int newY = oldY + offsetY[i];
                if (newX < 8 && newX >= 0 && newY < 8 && newY >= 0 && !map[newX][newY]) {
                    map[newX][newY] = true;
                    x.push(newX);
                    y.push(newY);
                    step.push(step_ + 1);
                }
            }
        }
        std::cout << "To get from " << (char)(x1 + 'a') << y1 + 1 << " to " << (char)(x2 + 'a') << y2 + 1 << " takes " << minStep << " knight moves." << std::endl;
        
    }
    return 0;
}
