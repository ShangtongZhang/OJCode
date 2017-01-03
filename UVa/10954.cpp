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

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    while (true) {
        int n;
        std::cin >> n;
        if (!n) {
            break;
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> nums;
        int tmp;
        while (n--) {
            std::cin >> tmp;
            nums.push(tmp);
        }
        int cost = 0;
        if (nums.size() > 1) {
            while (true) {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                cost += n1 + n2;
                if (nums.empty()) {
                    break;
                }
                nums.push(n1 + n2);
            }
        }
        std::cout << cost << std::endl;
    }
    return 0;
}
