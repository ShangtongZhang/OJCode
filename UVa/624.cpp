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

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int N;
    while (std::cin >> N) {
        int nTracks;
        std::cin >> nTracks;
        std::vector<int> tracks(nTracks);
        int sum = 0;
        for (auto& track : tracks) {
            std::cin >> track;
            sum += track;
        }
        N = std::min(N, sum);
        std::vector<std::vector<int>> D(nTracks + 1);
        for (auto& d : D) {
            d.resize(N + 1, 0);
        }
        auto selected = D;

        for (int i = 1; i <= nTracks; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (j >= tracks[i - 1]) {
                    int newD = D[i - 1][j - tracks[i - 1]] + tracks[i - 1];
                    if (D[i - 1][j] > newD) {
                        D[i][j] = D[i - 1][j];
                        selected[i][j] = false;
                    } else {
                        D[i][j] = newD;
                        selected[i][j] = true;
                    }
                } else {
                    D[i][j] = D[i - 1][j];
                    selected[i][j] = false;
                }
            }
        }
        int res = D[nTracks][N];
        int i = nTracks;
        int j = N;
        while (i) {
            if (selected[i][j]) {
                std::cout << tracks[i - 1] << ' ';
                j -= tracks[i - 1];
            }
            i--;
        }
        std::cout << "sum:" << D[nTracks][N] << std::endl;
    }
    return 0;
}