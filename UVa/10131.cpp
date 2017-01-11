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

class Node {
public:
    int data;
    int pos;
};

int L[1005][1005];
int track[1005][1005];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int w, s;
    int ind = 1;
    std::vector<Node> W, S;
    while (std::cin >> w >> s) {
        W.push_back(Node{w, ind});
        S.push_back(Node{s, ind});
        ind++;
    }
    std::sort(W.begin(), W.end(), [](Node& n1, Node& n2) {
        return n1.data > n2.data;
    });
    std::sort(S.begin(), S.end(), [](Node& n1, Node& n2) {
        return n1.data < n2.data;
    });
    int len = (int)W.size();
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (W[i - 1].pos == S[j - 1].pos) {
                L[i][j] = L[i - 1][j - 1] + 1;
                track[i][j] = W[i - 1].pos;
            } else {
                if (L[i - 1][j] > L[i][j - 1]) {
                    L[i][j] = L[i - 1][j];
                    track[i][j] = -1;
                } else {
                    L[i][j] = L[i][j - 1];
                    track[i][j] = -2;
                }
            }
        }
    }
    std::cout << L[len][len] << std::endl;
    int i, j;
    i = j = len;
    while (track[i][j]) {
        if (track[i][j] > 0) {
            std::cout << track[i][j] << std::endl;
            i--;
            j--;
        } else if (track[i][j] == -1) {
            i--;
        } else if (track[i][j] == -2) {
            j--;
        }
    }
    return 0;
}