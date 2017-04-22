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

int N, R, O, Y, G, B, V;

std::map<char, std::string> info = {{'R', "YB"}, {'Y', "RB"}, {'B', "RY"}};
std::map<char, int> count;

bool solve(std::string& stable) {
  if (stable.empty()) {
    if (R) {
      stable = "R";
      count['R']--;
    } else if (O) {
      stable = "O";
      count['O']--;
    } else if (Y) {
      stable = "Y";
      count['Y']--;
    } else if (G) {
      stable = "G";
      count['G']--;
    } else if (B) {
      stable = "B";
      count['B']--;
    } else if (V) {
      stable = "V";
      count['V']--;
    }
    return solve(stable);
  }
  if (stable.size() == N) {
    return stable.front() != stable.back();
  }
  auto& next = info[stable.back()];
  for (auto color : next) {
    if (count[color]) {
      stable.push_back(color);
      count[color]--;
      if (solve(stable)) {
        return true;
      }
      count[color]++;
      stable.pop_back();
    }
  }
  return false;
}

int main() {
  std::ifstream in("in.txt");
  std::cin.rdbuf(in.rdbuf());
  std::ofstream out("out.txt");
  std::cout.rdbuf(out.rdbuf());

  int T;
  std::cin >> T;
  for (int caseInd = 1; caseInd <= T; ++caseInd) {
    std::cin >> N >> R >> O >> Y >> G >> B >> V;
    count['R'] = R;
    count['O'] = O;
    count['Y'] = Y;
    count['G'] = G;
    count['B'] = B;
    count['V'] = V;
    std::string stable;
    std::cout << "Case #" << caseInd << ": ";
    if (solve(stable)) {
      std::cout << stable;
    } else {
      std::cout << "IMPOSSIBLE";
    }
    std::cout << std::endl;
  }

  return 0;
}