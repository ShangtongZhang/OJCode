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

class BigInt {
public:
    const static int BASE = 1000000000;
    const static int BASE_WIDTH = 9;
    int len;
    int data[30];

    BigInt() : len(1) {
        data[0] = 0;
    }

    BigInt(const BigInt &v) : len(v.len) {
        memcpy(data, v.data, len * sizeof(int));
    }
    BigInt(int v) : len(0) {
        while (v > 0)
            data[len++] = v % BASE, v /= BASE;
    }
    BigInt &operator = (const BigInt &v) {
        len = v.len;
        memcpy(data, v.data, len * sizeof(int));
        return *this;
    }
    int &operator [] (int i) {
        return data[i];
    }
    int operator [] (int i) const {
        return data[i];
    }
    operator std::string() {
        std::stringstream ss;
        for (int i = len - 1; i >= 0; --i) {
            if (i < len - 1) {
                std::cout << std::setw(BASE_WIDTH) << std::setfill('0') << data[i];
            } else {
                std::cout << data[i];
            }
        }
        return ss.str();
    }
};

BigInt operator + (const BigInt &a, const BigInt &b)
{
    BigInt r;
    int i, carry = 0;
    for (i = 0; i < a.len || i < b.len || 0 < carry; ++i)
    {
        if (i < a.len)
            carry += a[i];
        if (i < b.len)
            carry += b[i];
        r[i] = carry % BigInt::BASE;
        carry /= BigInt::BASE;
    }
    r.len = i;
    return r;
}

BigInt D[10010][105];

int main() {
//    std::ifstream in("in.txt");
//    std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("out.txt");
//    std::cout.rdbuf(out.rdbuf());

    int nCase;
    std::cin >> nCase;
    std::string tmp;
    std::getline(std::cin, tmp);
    while (nCase--) {
        std::string X, Z;
        std::getline(std::cin, X);
        std::getline(std::cin, Z);
        int xl = X.size();
        int zl = Z.size();
        if (!xl || !zl) {
            std::cout << 0 << std::endl;
            continue;
        }
        for (int i = 1; i <= xl; ++i) {
            for (int j = 1; j <= zl; ++j) {
                if (X[i - 1] == Z[j - 1]) {
                    if (j == 1) {
                        D[i][j] = 1 + D[i - 1][j];
                    } else {
                        D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
                    }
                } else {
                    D[i][j] = D[i - 1][j];
                }
            }
        }
        std::cout << (std::string)D[xl][zl] << std::endl;
    }
    return 0;
}