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

constexpr int size = 25;
constexpr int nDirections = 4;
constexpr int nColors = 5;
char map[size][size];
bool flag[size][size][nDirections][nColors];
std::pair<int, int> offsets[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    int row, col;
    int nCase = 0;
    while (true) {
        std::cin >> row >> col;
        if (row == 0 || col == 0) {
            break;
        }
        nCase++;
        if (nCase > 1) {
            std::cout << std::endl;
        }
        std::queue<std::tuple<int, int, int, int, int>> path;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                std::cin >> map[i][j];
                if (map[i][j] == 'S') {
                    path.push(std::make_tuple(i, j, 0, 0, 0));
                }
            }
        }
        int x, y, color, direction, seconds = 0;
        bool reachable = false;
        std::memset(flag, 0, sizeof(flag));
        while (!path.empty()) {
            auto node = path.front();
            x = std::get<0>(node);
            y = std::get<1>(node);
            color = std::get<2>(node);
            direction = std::get<3>(node);
            seconds = std::get<4>(node);
            path.pop();
            if (x < 0 || x >= row || y < 0 || y >= col || map[x][y] == '#' || flag[x][y][direction][color]) {
                continue;
            }
            flag[x][y][direction][color] = true;
            if (map[x][y] == 'T' && color == 0) {
                reachable = true;
                break;
            }
            auto& offset = offsets[direction];
            path.push(std::make_tuple(x + offset.first, y + offset.second, (color + 1) % nColors, direction, seconds + 1));
            path.push(std::make_tuple(x, y, color, (direction + 1) % nDirections, seconds + 1));
            path.push(std::make_tuple(x, y, color, (direction + 3) % nDirections, seconds + 1));
        }
        std::cout << "Case #" << nCase << std::endl;
        if (reachable) {
            std::cout << "minimum time = " << seconds << " sec" << std::endl;
        } else {
            std::cout << "destination not reachable" << std::endl;
        }
    }
    return 0;
}
