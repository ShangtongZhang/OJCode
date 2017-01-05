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

bool reduce(int from, int to, int A, int B, int& cost) {
    if (from == to) {
        return true;
    }
    if (from < to) {
        return false;
    }
    if ((from - from / 2) * A > B) {
        cost += B;
        if (reduce(from / 2, to, A, B, cost)){
            return true;
        }
        cost -= B;
    }
    cost += A;
    if (reduce(from - 1, to, A, B, cost)) {
        return true;
    }
    cost -= A;
    return false;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    for (int index = 1; index <= nCase; ++index) {
        int from, to, nAgency;
        std::cin >> from >> to >> nAgency;
        std::string line;
        std::getline(std::cin, line);
        using T = std::pair<std::string, int>;
        std::vector<T> res;
        while (nAgency--) {
            std::getline(std::cin, line);
            auto it = std::find(line.begin(), line.end(), ':');
            *it = ' ';
            it = std::find(line.begin(), line.end(), ',');
            *it = ' ';
            std::stringstream ss(line);
            std::string name;
            int A, B;
            ss >> name >> A >> B;
            int cost = 0;
            reduce(from, to, A, B, cost);
            res.push_back(std::make_pair(name, cost));
        }
        std::sort(res.begin(), res.end(), [](T& t1, T& t2) {
            if (t1.second != t2.second) {
                return t1.second < t2.second;
            }
            return t1.first < t2.first;
        });
        std::cout << "Case " << index << std::endl;
        for (auto& t : res) {
            std::cout << t.first << ' ' << t.second << std::endl;
        }
    }
    return 0;
}
