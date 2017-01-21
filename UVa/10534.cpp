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

constexpr int MAX = 10005;
constexpr int INF = 0x7fffffff;
int nums[MAX];
int N;
int INC[MAX];
int DEC[MAX];

int stack[MAX];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    while (std::cin >> N) {
        for (int i = 0; i < N; ++i) {
            std::cin >> nums[i];
        }

        stack[0] = -INF;

        int top = 0;
        for (int i = 0; i < N; ++i) {
            if (nums[i] > stack[top]) {
                stack[++top] = nums[i];
            } else {
                int* end = stack + top + 1;
                int* p = std::lower_bound(stack, end, nums[i]);
                if (p < end) {
                    *p = nums[i];
                }
            }
            INC[i] = top;
        }

        top = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (nums[i] > stack[top]) {
                stack[++top] = nums[i];
            } else {
                int* end = stack + top + 1;
                int *p = std::lower_bound(stack, stack + top + 1, nums[i]);
                if (p < end) {
                    *p = nums[i];
                }
            }
            DEC[i] = top;
        }

        int maxLen = -MAX;
        for (int i = 0; i < N; ++i) {
            maxLen = std::max(maxLen, std::min(INC[i], DEC[i]));
        }
        std::cout << 2 * maxLen - 1 << std::endl;
    }

    return 0;
}