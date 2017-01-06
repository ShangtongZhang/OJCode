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
        std::priority_queue<int> nums;
        while (n--) {
            int tmp;
            std::cin >> tmp;
            if (tmp > 0) {
                nums.push(tmp);
            }
        }
        bool flag = true;
        while (!nums.empty()) {
            int cur = nums.top();
            nums.pop();
            if (nums.size() < cur) {
                flag = false;
                break;
            }
            std::vector<int> nexts;
            while (cur--) {
                int next = nums.top();
                nums.pop();
                next--;
                if (next > 0) {
                    nexts.push_back(next);
                }
            }
            for (auto& n : nexts) {
                nums.push(n);
            }
            
        }
        
        std::cout << (flag ? "Possible" : "Not possible") << std::endl;
    }
    return 0;
}
