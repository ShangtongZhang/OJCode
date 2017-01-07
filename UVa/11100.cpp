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
    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        std::map<int, int> nums;
        for (int i = 0; i < n; ++i) {
            int tmp;
            std::cin >> tmp;
            if (nums.find(tmp) == nums.end()) {
                nums[tmp] = 1;
            } else {
                nums[tmp] += 1;
            }
        }
        using T = std::pair<int, int>;
        std::vector<T> counts;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            counts.push_back(std::make_pair(it->first, it->second));
        }
        std::sort(counts.begin(), counts.end(), [](T& n1, T& n2) {
            return n1.second > n2.second;
        });
        size_t nPieces = counts.front().second;
        size_t nBags = n / nPieces + !!(n % nPieces);
        std::vector<std::vector<int>> pieces(nPieces);
        for (auto& bag : counts) {
            std::sort(pieces.begin(), pieces.end(), [](std::vector<int>& p1, std::vector<int>& p2) {
                return p1.size() < p2.size();
            });
            int i = 0;
            while (bag.second) {
                while (pieces[i].size() == nBags) {
                    i++;
                }
                pieces[i].push_back(bag.first);
                i++;
                bag.second--;
            }
        }
        std::cout << nPieces << std::endl;
        for (auto& piece : pieces) {
            for (auto it = piece.begin() ; it != piece.end(); ++it) {
                if (it != piece.begin()) {
                    std::cout << ' ';
                }
                std::cout << *it;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
