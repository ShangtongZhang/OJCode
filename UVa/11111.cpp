#include "iostream"
#include "vector"
#include "math.h"
#include "map"
#include "string"
#include "list"
#include "set"
#include "algorithm"
#include "sstream"

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int num;
        std::vector<int> info;
        std::vector<int> sum;
        bool flag = true;
        while (iss >> num) {
            if (num < 0) {
                info.push_back(num);
                sum.push_back(0);
                continue;
            }
            if (num > 0) {
                if (info.empty() || info.back() + num != 0) {
                    flag = false;
                    break;
                }
                info.pop_back();
                sum.pop_back();
                if (!sum.empty()) {
                    sum.back() += num;
                    if (sum.back() >= -info.back()) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        std::cout << (flag && info.empty() ? ":-) Matrioshka!" : ":-( Try again.") << std::endl;
    }
    return 0;
}
