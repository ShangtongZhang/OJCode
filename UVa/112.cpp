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

bool travelTree(char& tmp, long long sum, int target, bool& flag) {
    int data = 0;
    int sign = 1;
    while (scanf("%c", &tmp) != EOF) {
        if (tmp == ' ' || tmp == '\n') {
            continue;
        }
        if (tmp == ')') {
            return false;
        }
        if (tmp == '(') {
            break;
        }
        if (isdigit(tmp)) {
            data = 10 * data + (tmp - '0');
        }
        if (tmp == '-') {
            sign = -1;
        }
    }
    data *= sign;
    sum += data;
    bool hasLeft = travelTree(tmp, sum, target, flag);
    while (scanf("%c", &tmp) != EOF && tmp != '(');
    bool hasRight = travelTree(tmp, sum, target, flag);
    while (scanf("%c", &tmp) != EOF && tmp != ')');
    if (!hasLeft && !hasRight && sum == target) {
        flag = true;
    }
    return true;
}

int main() {
//    freopen("data.txt", "r", stdin);
    int target = 0;
    while (scanf("%d", &target) != EOF) {
        char tmp = 0;
        while (scanf("%c", &tmp) != EOF && tmp != '(');
        bool flag = false;
        travelTree(tmp, 0, target, flag);
        std::cout << (flag ? "yes" : "no") << std::endl;
    }
    return 0;
}
