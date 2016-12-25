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

bool match(std::string& str, std::string& pattern) {
    auto itS = str.begin();
    auto itP = pattern.begin();
    while (true) {
        if (itP == pattern.end() && itS == str.end()) {
            return true;
        }
        if (itP == pattern.end() && itS != str.end()) {
            return false;
        }
        if (itP != pattern.end() && itS == str.end()) {
            return *itP == '*';
        }
        if (*itP == '?') {
            ++itS;
            ++itP;
        } else if (*itP == '*') {
            return true;
        } else {
            if (*itP == *itS) {
                ++itS;
                ++itP;
            } else {
                return false;
            }
        }
    }
}

std::vector<std::string> posName;
std::vector<std::string> posExt;
std::vector<std::string> negName;
std::vector<std::string> negExt;

bool check(std::string& str, std::string::iterator it, std::string& pattern, std::vector<std::string>& posWords, std::vector<std::string>& negWords) {
    if (it == str.end()) {
        for (auto& word : posWords) {
            if (!match(word, pattern)) {
                return false;
            }
        }
        for (auto& word : negWords) {
            if (match(word, pattern)) {
                return false;
            }
        }
        return true;
    } else {
        pattern += *it;
        if (check(str, std::next(it), pattern, posWords, negWords)) {
            return true;
        }
        pattern += '*';
        if (check(str, str.end(), pattern, posWords, negWords)) {
            return true;
        }
        pattern.pop_back();
        pattern.back() = '?';
        if (check(str, std::next(it), pattern, posWords, negWords)) {
            return true;
        }
        pattern += '*';
        if (check(str, str.end(), pattern, posWords, negWords)) {
            return true;
        }
        pattern.pop_back();
        pattern.pop_back();
        return false;
    }
}

std::string solve(std::string& name, std::string& ext) {
    std::string namePattern;
    std::string extPattern;
    if (check(name, name.begin(), namePattern, posName, negName)) {
        return namePattern + "." + (ext.empty() ? "" : "*");
    } else if (check(ext, ext.begin(), extPattern, posExt, negExt)) {
        return "*." + extPattern;
    }
    return "";
}

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n = 0;
    std::cin >> n;
    std::string line;
    std::getline(std::cin, line);
    std::getline(std::cin, line);
    while (n > 0) {
        posName.clear();
        posExt.clear();
        negName.clear();
        negExt.clear();
        while (!std::cin.eof()) {
            std::getline(std::cin, line);
            if (line.empty()) {
                break;
            }
            auto it = std::find(line.begin(), line.end(), '.');
            auto name = std::string(std::next(line.begin()), it);
            auto ext = it == line.end() ? "" : std::string(std::next(it), line.end());
            if (line.front() == '-') {
                posName.push_back(name);
                posExt.push_back(ext);
            } else {
                negName.push_back(name);
                negExt.push_back(ext);
            }
        }
        auto name = posName.back();
        posName.pop_back();
        auto ext = posExt.back();
        posExt.pop_back();
        auto pattern = solve(name, ext);
        if (pattern.empty()) {
            std::cout << "IMPOSSIBLE" << std::endl;
        } else {
            std::cout << "DEL " << pattern << std::endl;
        }
        if (n > 1) {
            std::cout << std::endl;
        }
        n--;
    }
    
    return 0;
}
