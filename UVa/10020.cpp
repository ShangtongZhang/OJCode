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
#include "bitset"
#include "unordered_map"
#include "unordered_set"

class Node {
public:
    int L;
    int R;
};

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n;
    std::cin >> n;
    bool first = true;
    while (n--) {
        if (!first) {
            std::cout << std::endl;
        }
        first = false;
        int M, L, R;
        std::cin >> M;
        std::list<Node> segs;
        std::vector<Node> selected;
        while (true) {
            std::cin >> L >> R;
            if (!L && !R) {
                break;
            }
            if (R < 0 || L > M) {
                continue;
            }
            segs.push_back(Node{L, R});
        }
        segs.sort([](Node& n1, Node& n2) {
            if (n1.L != n2.L) {
                return n1.L < n2.L;
            }
            return n1.R < n2.R;
        });
//        std::sort(segs.begin(), segs.end(), [](Node& n1, Node& n2) {
//            if (n1.L != n2.L) {
//                return n1.L < n2.L;
//            }
//            return n1.R < n2.R;
//        });
        int cur = 0;
        bool flag = true;
        while (cur < M) {
            auto it = segs.begin();
            auto selectedIt = segs.end();
            int maxR = cur;
            while (it != segs.end()) {
                if (it->R < cur) {
                    it = segs.erase(it);
                    continue;
                }
                if (it->L <= cur && it->R > maxR) {
                    maxR = it->R;
                    selectedIt = it;
                }
                it++;
            }
            if (selectedIt == segs.end()) {
                flag = false;
                break;
            }
            selected.push_back(*selectedIt);
            cur = selectedIt->R;
        }
        if (flag) {
            std::cout << selected.size() << std::endl;
            for (auto& seg : selected) {
                std::cout << seg.L << ' ' << seg.R << std::endl;
            }
        } else {
            std::cout << 0 << std::endl;
        }

    }
    return 0;
}
