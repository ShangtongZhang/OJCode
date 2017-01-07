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
constexpr int INF = 0x7FFFFFFF;

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int n;
    std::cin >> n;
    int ind = 1;
    while (n--) {
        int r;
        std::cin >> r;
        std::vector<int> nums(r - 1);
        std::vector<int> sums(r);
        for (size_t i = 0; i < nums.size(); ++i) {
            std::cin >> nums[i];
            sums[i + 1] = nums[i] + sums[i];
        }
        std::vector<int> minSum(r);
        std::vector<int> minSumInd(r);
        for (size_t i = 0; i < minSum.size(); ++i) {
            if (i == 0) {
                minSum[i] = sums[i];
                minSumInd[i] = 0;
            } else {
                if (minSum[i - 1] <= sums[i]) {
                    minSum[i] = minSum[i - 1];
                    minSumInd[i] = minSumInd[i - 1];
                } else {
                    minSum[i] = sums[i];
                    minSumInd[i] = (int)i;
                }
            }
        }
        int maxSum = -INF;
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i < (int)sums.size(); ++i) {
            int curSum = sums[i] - minSum[i];
            if (curSum > maxSum) {
                maxSum = curSum;
                pos1 = minSumInd[i];
                pos2 = i;
            } else if (curSum == maxSum) {
                if (i - minSumInd[i] > pos2 - pos1) {
                    pos1 = minSumInd[i];
                    pos2 = i;
                } else if (i - minSumInd[i] == pos2 - pos1) {
                    if (minSumInd[i] < pos1) {
                        pos1 = minSumInd[i];
                        pos2 = i;
                    }
                }
            }
        }
        if (maxSum <= 0) {
            std::cout << "Route " << ind << " has no nice parts" << std::endl;
        } else {
            std::cout << "The nicest part of route " << ind << " is between stops " << pos1 + 1 << " and " << pos2 + 1 << std::endl;
        }
        ind++;
    }
    return 0;
}
