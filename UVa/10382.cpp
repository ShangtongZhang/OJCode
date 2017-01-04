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
    double L;
    double R;
};

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n, length, width;
    while (std::cin >> n >> length >> width) {
        double h = width / 2.0;
        int p, r;
        std::list<Node> segs;
        while (n--) {
            std::cin >> p >> r;
            double w2 = (double)r * r - h * h;
            if (w2 > 0) {
                double w = std::sqrt(w2);
                segs.push_back(Node{(double)p - w, (double)p + w});
            }
        }
        segs.sort([](Node& n1, Node& n2) {
            if (n1.L != n2.L) {
                return n1.L < n2.L;
            }
            return n1.R < n2.R;
        });
        double cur = 0;
        int count = 0;
        while (cur < length) {
            auto selected = segs.end();
            auto maxR = 0;
            auto it = segs.begin();
            while (it != segs.end()) {
                if (it->R < cur) {
                    it = segs.erase(it);
                } else {
                    if (it->L <= cur) {
                        if (it->R > maxR) {
                            maxR = it->R;
                            selected = it;
                        }
                        it++;
                    } else {
                        break;
                    }
                }
            }
            if (selected != segs.end()) {
                count++;
                cur = selected->R;
                segs.erase(selected);
            } else {
                break;
            }
        }
        std::cout << (cur < length ? -1 : count) << std::endl;
    }
    return 0;
}
