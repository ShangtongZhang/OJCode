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

class Solution {
public:
  std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
    std::vector<int> time(n);
    std::vector<int> procs;
    std::vector<int> timesteps;
    for (auto& log : logs) {
      int id;
      int timestep;
      bool start = parse(log, id, timestep);
      if (start) {
        if (!procs.empty()) {
          time[procs.back()] += timestep - timesteps.back();
        }
        procs.push_back(id);
        timesteps.push_back(timestep);
      } else {
        time[procs.back()] += timestep + 1 - timesteps.back();
        procs.pop_back();
        timesteps.pop_back();
        if (!procs.empty()) {
          timesteps.back() = timestep + 1;
        }
      }
    }
    return time;
  }

  bool parse(std::string& log, int& id, int& timestep) {
    int p1 = log.find(':');
    int p2 = log.rfind(':');
    id = std::stoi(log.substr(0, p1));
    timestep = std::stoi(log.substr(p2 + 1));
    return log[p1 + 1] == 's';
  }
};

int main() {
//  std::ifstream in("in.txt");
//  std::cin.rdbuf(in.rdbuf());
//  std::ofstream out("out.txt");
//  std::cout.rdbuf(out.rdbuf());
  Solution s;
  std::vector<std::string> logs{"0:start:0",
                                "1:start:2",
                                "1:end:5",
                                "0:end:6"};
  auto res = s.exclusiveTime(2, logs);

  return 0;
}