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
    int l;
    int r;
};
int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    auto cmpR = [](const Node& n1, const Node& n2) {
        return n1.r < n2.r;
    };
    auto cmpL = [](const Node& n1, const Node& n2) {
        return n1.l < n2.l;
    };
    int nCase;
    std::cin >> nCase;
    bool first = true;
    while (nCase--) {
        if (first) {
            first = false;
        } else {
            std::cout << std::endl;
        }
        int nAd, nJog;
        std::cin >> nAd >> nJog;
        std::vector<Node> jogs(nJog);
        for (auto& jog : jogs) {
            int n1, n2;
            std::cin >> n1 >> n2;
            jog.l = std::min(n1, n2);
            jog.r = std::max(n1, n2);
        }
        std::sort(jogs.begin(), jogs.end(), cmpR);
        std::set<int> ads;
        for (auto& jog : jogs) {
            int rAd = nAd;
            for (int i = jog.l; i <= jog.r; ++i) {
                if (ads.find(i) != ads.end()) {
                    rAd--;
                    if (rAd == 0) {
                        break;
                    }
                }
            }
            int pos = jog.r;
            while (rAd && pos >= jog.l) {
                if (ads.find(pos) == ads.end()) {
                    ads.insert(pos);
                    rAd--;
                }
                pos--;
            }
        }
        std::cout << ads.size() << std::endl;
        for (auto it = ads.begin(); it != ads.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}