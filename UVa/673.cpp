#include "iostream"
#include "vector"
#include "math.h"
#include "map"
#include "string"
#include "list"
#include "set"
#include "algorithm"

int main() {
    int n = 0;
    std::cin >> n;
    std::cin.ignore(100, '\n');
    while (n--) {
        std::string str;
        std::getline(std::cin, str);
        std::vector<char> info;
        bool flag = true;
        for (auto it = str.begin(); it != str.end(); ++it) {
            if (info.empty() || *it == '(' || *it == '[') {
                info.push_back(*it);
                continue;
            }
            if ((*it == ')' && info.back() != '(') ||
                (*it == ']' && info.back() != '[')) {
                flag = false;
                break;
            }
            info.pop_back();
        }
        std::cout << (flag && info.empty() ? "Yes" : "No") << std::endl;
    }
    return 0;
}
