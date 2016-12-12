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

void DFS(std::vector<std::string>& map, int i, int j, int row, int col) {
    if (i < 0 || i >= row || j < 0 || j >= col) {
        return;
    }
    if (map[i][j] != '@') {
        return;
    }
    map[i][j] = 0;
    DFS(map, i - 1, j - 1, row, col);
    DFS(map, i - 1, j, row, col);
    DFS(map, i - 1, j + 1, row, col);
    DFS(map, i, j - 1, row, col);
    DFS(map, i, j + 1, row, col);
    DFS(map, i + 1, j - 1, row, col);
    DFS(map, i + 1, j, row, col);
    DFS(map, i + 1, j + 1, row, col);
}

int main() {
    int row = 0;
    int col = 0;
    std::vector<std::string> map;
    std::string line;
    while (std::cin >> row >> col) {
        if (row == 0 && col == 0) {
            break;
        }
        map.clear();
        int count = 0;
        for (int i = 0; i < row; ++i) {
            std::cin >> line;
            map.push_back(std::move(line));
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (map[i][j] == '@') {
                    count++;
                    DFS(map, i, j, row, col);
                }
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
