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

void check(std::vector<int>& xs, std::vector<int>& ys, int& A, int &B) {
    for (A = -500; A <= 500; ++A) {
        for (B = -500; B <= 500; ++B) {
            int count1 = 0;
            int count2 = 0;
            for (size_t i = 0; i < xs.size(); ++i) {
                int flag = A * xs[i] + B * ys[i];
                if (flag == 0) {
                    i = xs.size();
                } else if (flag > 0) {
                    count1++;
                } else {
                    count2++;
                }
            }
            if (count1 == count2 && count1 == xs.size() / 2) {
                return;
            }
        }
    }
}

int main() {
//        std::ifstream in("in.txt");
//        std::cin.rdbuf(in.rdbuf());
//        std::ofstream out("out.txt");
//        std::cout.rdbuf(out.rdbuf());
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        n *= 2;
        int x, y;
        std::vector<int> xs;
        std::vector<int> ys;
        while (n--) {
            std::cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }
        int A, B;
        check(xs, ys, A, B);
        std::cout << A << ' ' << B << std::endl;
    }
    return 0;
}
