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

bool check(std::vector<int>& books, int nParts, long long int limit) {
    int sum = 0;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (sum + *it <= limit) {
            sum += *it;
        } else {
            sum = *it;
            if (sum > limit) {
                return false;
            }
            nParts--;
            if (nParts == 0) {
                break;
            }
        }
    }
    return nParts;
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    while (nCase--) {
        int m, k;
        long long int l = 0, r = 0;
        std::cin >> m >> k;
        std::vector<int> books(m);
        for (auto& book : books) {
            std::cin >> book;
            r += book;
        }
        while (l < r) {
            long long int mid = (r + l) / 2;
            if (check(books, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        long long int limit = l;
        int sum = 0;
        int nParts = k;
        std::list<int> sol;
        for (auto it = books.rbegin(); it != books.rend(); ++it) {
            if (sum + *it <= limit) {
                sum += *it;
            } else {
                sum = *it;
                sol.push_front(-1);
                nParts--;
            }
            sol.push_front(*it);
        }
        auto it = sol.begin();
        while (nParts > 1) {
            if (*it != -1 && *std::next(it) != -1) {
                it = sol.insert(std::next(it), -1);
                nParts--;
            }
            it++;
        }
        for (auto it = sol.begin(); it != sol.end(); ++it) {
            if (it != sol.begin()) {
                std::cout << ' ';
            }
            if (*it == -1) {
                std::cout << '/';
            } else {
                std::cout << *it;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
