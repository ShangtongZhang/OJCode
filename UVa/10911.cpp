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

using bit = std::bitset<16>;
float D[1 << 17];
bool flag[1 << 17];
int xs[17];
int ys[17];
int N;

float solve(bit& persons) {
    int ind = persons.to_ulong();
    if (ind == 0) {
        return 0;
    }
    if (flag[ind]) {
        return D[ind];
    }
    flag[ind] = true;
    D[ind] = std::numeric_limits<float>::max();
    int i = 0;
    while (!persons[i]) {
        ++i;
    }
    persons[i] = false;
    for (int j = i + 1; j < N; ++j) {
        if (persons[j]) {
            persons[j] = false;
            int dx = xs[i] - xs[j];
            int dy = ys[i] - ys[j];
            D[ind] = std::min(D[ind], solve(persons) + (float)std::sqrt(dx * dx + dy * dy));
            persons[j] = true;

        }
    }
    persons[i] = true;
    return D[ind];
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    std::string tmp;
    int caseInd = 0;
    while (true) {
        std::cin >> N;
        if (!N) {
            break;
        }
        caseInd++;
        N *= 2;
        for (int i = 0; i < N; ++i) {
            std::cin >> tmp;
            std::cin >> xs[i] >> ys[i];
        }
        std::memset(D, 0, sizeof(D));
        std::memset(flag, 0, sizeof(flag));
        bit persons;
        for (int i = 0; i < N; ++i) {
            persons[i] = true;
        }
        std::cout << "Case " << caseInd << ": "
                  << std::fixed << std::setprecision(2) << solve(persons) << std::endl;
    }
    return 0;
}