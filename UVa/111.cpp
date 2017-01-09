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

constexpr int MAX_N = 25;
int d[MAX_N][MAX_N];
int answer[MAX_N];
int events[MAX_N];
int trial[MAX_N];

int solve(int i, int j) {
    if (i == 0) {
        return trial[0] == j;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    int pos = events[j];
    int maxLen = -MAX_N;
    if (trial[i] != j) {
        maxLen = std::max(maxLen, solve(i - 1, j));
    } else {
        for (int k = 0; k < pos; ++k) {
            maxLen = std::max(maxLen, solve(i - 1, answer[k]) + 1);
        }
    }
    d[i][j] = maxLen;
    return maxLen;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    std::string line;
    int n;
    bool isAnswer;
    while (!std::cin.eof()) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (line.find(' ') == std::string::npos) {
            ss >> n;
            isAnswer = true;
        } else {
            if (isAnswer) {
                for (int i = 1; i <= n; ++i) {
                    ss >> events[i];
                    answer[events[i] - 1] = i;
                }
                isAnswer = false;
            } else {
                std::memset(d, -1, sizeof(d));
                for (int i = 1; i <= n; ++i) {
                    int rank;
                    ss >> rank;
                    trial[rank - 1] = i;
                }
                int maxLen = -MAX_N;
                for (int i = 1; i <= n; ++i) {
                    maxLen = std::max(maxLen, solve(n - 1, i));
                }
                std::cout << maxLen << std::endl;
            }
        }
    }
    return 0;
}