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

std::vector<int> value(26);

int fromRoman(const std::string& str) {
    int v = 0;
    for (auto it = str.begin(); it != str.end(); ++it) {
        auto itN = std::next(it);
        if (itN == str.end() || value[*itN - 'A'] <= value[*it - 'A']) {
            v += value[*it - 'A'];
        } else {
            v -= value[*it - 'A'];
        }
    }
    return v;
}

std::string op1, op2, op3;
int n1, n2, n3;

void checkArabic(std::string::iterator it, int* pn, std::vector<int>& map, int& count) {
    if (count > 1) {
        return;
    }
    if (it == op1.begin() || it == op2.begin() || it == op3.begin()) {
        if (map[*it - 'A'] == 0) {
            return;
        }
    }
    if (it == op3.end()) {
        if (n1 + n2 == n3) {
            count++;
            return;
        }
        return;
    }
    if (it == op1.end()) {
        it = op2.begin();
        pn = &n2;
    }
    if (it == op2.end()) {
        it = op3.begin();
        pn = &n3;
    }
    if (map[*it - 'A'] != -1) {
        *pn = 10 * *pn + map[*it - 'A'];
        checkArabic(std::next(it), pn, map, count);
        *pn /= 10;
    } else {
        for (int i = 0; i < 10; ++i) {
            map[*it - 'A'] = i;
            checkArabic(it, pn, map, count);
            map[*it - 'A'] = -1;
        }
    }
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());
    value['I' - 'A'] = 1;
    value['X' - 'A'] = 10;
    value['C' - 'A'] = 100;
    value['M' - 'A'] = 1000;
    value['V' - 'A'] = 5;
    value['L' - 'A'] = 50;
    value['D' - 'A'] = 500;
    std::string str;
    while (true) {
        std::cin >> str;
        if (*str.begin() == '#') {
            break;
        }
        auto it1 = std::find(str.begin(), str.end(), '+');
        auto it2 = std::find(str.begin(), str.end(), '=');
        op1 = std::move(std::string(str.begin(), it1));
        op2 = std::move(std::string(std::next(it1), it2));
        op3 = std::move(std::string(std::next(it2), str.end()));
        n1 = fromRoman(op1);
        n2 = fromRoman(op2);
        n3 = fromRoman(op3);
        bool correct = n1 + n2 == n3;
        n1 = n2 = n3 = 0;
        int count = 0;
        std::vector<int> map(26, -1);
        auto it = op1.begin();
        checkArabic(it, &n1, map, count);
        std::cout << (correct ? "Correct " : "Incorrect ");
        std::cout << (count == 0 ? "impossible" : (count == 1 ? "valid" : "ambiguous")) << std::endl;
    }
}
