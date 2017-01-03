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

constexpr int BITS = 32;

std::bitset<BITS> pad(std::bitset<BITS> n, int pos, bool fill) {
    auto m = n;
    for (int i = pos - 1; i >= 0; --i) {
        m[i] = fill;
    }
    return m;
}

void solve(std::bitset<BITS>& n, std::bitset<BITS>& m, int pos, unsigned int l, unsigned int r) {
    if (pos < 0) {
        return;
    }
    if (n[pos]) {
        m[pos] = false;
        if (pad(m, pos, true).to_ulong() >= l && pad(m, pos, false).to_ulong() <= r) {
            solve(n, m, pos - 1, l, r);
            return;
        }
        m[pos] = true;
        if (pad(m, pos, true).to_ulong() >= l && pad(m, pos, false).to_ulong() <= r) {
            solve(n, m, pos - 1, l, r);
            return;
        }
    } else {
        m[pos] = true;
        if (pad(m, pos, true).to_ulong() >= l && pad(m, pos, false).to_ulong() <= r) {
            solve(n, m, pos - 1, l, r);
            return;
        }
        m[pos] = false;
        if (pad(m, pos, true).to_ulong() >= l && pad(m, pos, false).to_ulong() <= r) {
            solve(n, m, pos - 1, l, r);
            return;
        }
    }
}

int main() {
    unsigned int n, l, r;
    while (std::cin >> n >> l >> r) {
        std::bitset<BITS> op(n);
        std::bitset<BITS> m(0);
        solve(op, m, BITS - 1, l, r);
        std::cout << m.to_ulong() << std::endl;
    }
    return 0;
}
