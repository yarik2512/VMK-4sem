#include <map>
#include <iostream>
#include <cstdint>

constexpr uint64_t MOD = 4294967161;

struct coords {
    uint32_t i;
    uint32_t j;

    coords(uint32_t i_, uint32_t j_) : i(i_), j(j_) {}

    bool operator<(const coords &c) const {
        if (i == c.i) {
            return j < c.j;
        }
        return i < c.i;
    }
};

int main() {
    using std::map, std::pair, std::cin, std::cout, std::endl;
    map<coords, uint64_t> matrix;
    uint32_t i, j;
    uint64_t v;
    while (cin >> i >> j >> v) {
        if (i == 0 && j == 0 && v == MOD) {
            break;
        }
        matrix[{i, j}] = v % MOD;
    }
    while (cin >> i >> j >> v) {
        matrix[{i, j}] += v % MOD;
    }
    for (const pair<const coords, uint64_t> &el: matrix) {
        if (el.second % MOD == 0) {
            continue;
        }
        cout << el.first.i << ' ' << el.first.j << ' ' << el.second % MOD << endl;
    }
    return 0;
}
