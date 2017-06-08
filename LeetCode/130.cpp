#include "iostream"
#include "vector"
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
#include "unordered_map"
#include "unordered_set"
#include "numeric"
#include "cmath"

class Solution {
public:
  class Node {
  public:
    int x;
    int y;
  };
  int row;
  int col;
  std::vector<std::vector<char>> board;
  std::vector<std::vector<int>> visited;
  bool isFree(int x, int y) {
    return x == 0 || x == row - 1 || y == 0 || y == col - 1;
  }

  bool bfs(int x, int y) {
    std::queue<Node> path;
    path.push(Node{x, y});
    while (!path.empty()) {
      auto cur = path.front();
      path.pop();
      if (cur.x < 0 || cur.y < 0 || cur.x >= row || cur.y >= col || board[cur.x][cur.y] == 'X') { continue; }
      if (visited[cur.x][cur.y] == 1) { continue; }
      visited[cur.x][cur.y] = 1;
      if (isFree(cur.x, cur.y)) { return true; }
      path.push(Node{cur.x, cur.y + 1});
      path.push(Node{cur.x, cur.y - 1});
      path.push(Node{cur.x - 1, cur.y});
      path.push(Node{cur.x + 1, cur.y});
    }
    return false;
  }

  void fill(int x, int y, char symbol) {
    std::queue<Node> path;
    path.push(Node{x, y});
    while (!path.empty()) {
      auto cur = path.front();
      path.pop();
      if (cur.x < 0 || cur.y < 0 || cur.x >= row || cur.y >= col || board[cur.x][cur.y] == 'X') { continue; }
      if (visited[cur.x][cur.y] == 2) { continue; }
      visited[cur.x][cur.y] = 2;
      board[cur.x][cur.y] = symbol;
      path.push(Node{cur.x, cur.y + 1});
      path.push(Node{cur.x, cur.y - 1});
      path.push(Node{cur.x - 1, cur.y});
      path.push(Node{cur.x + 1, cur.y});
    }
  }

  void solve(std::vector<std::vector<char>>& board) {
    if (board.empty()) {
      return;
    }
    row = board.size();
    col = board.front().size();
    this->board = std::move(board);
    visited.resize(row);
    for (auto& row : visited) { row.resize(col); }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (this->board[i][j] == 'O') {
          if (bfs(i, j)) {
            fill(i, j, 'F');
          } else {
            fill(i, j, 'X');
          }
        }
      }
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (this->board[i][j] == 'F') {
          this->board[i][j] = 'O';
        }
      }
    }
    board = std::move(this->board);
  }
};

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  std::vector<std::vector<char>> board;
  int row = 6;
  int col = 6;
  board.resize(row);
  for (int i = 0; i < row; ++i) {
    board[i].resize(col);
    for (int j = 0; j < col; ++j) {
      std::cin >> board[i][j];
    }
  }
  Solution s;
  s.solve(board);
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      std::cout << board[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}