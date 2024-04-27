#include <iostream>
#include <map>
#include <cstdint>

constexpr uint64_t MOD = 4294967161;

int main() {
    using std::map, std::cin, std::cout, std::endl;
    map<uint32_t, map<uint32_t, uint64_t>> m;
    map<uint32_t, map<uint32_t, uint64_t>> res;
    uint32_t i, j;
    uint64_t v;
    while (cin >> i >> j >> v) {
        if (i == 0 && j == 0 && v == MOD) {
            break;
        }
        m[j][i] = v % MOD;
    }
    while (cin >> i >> j >> v) {
        const auto col = m.find(i);
        if (col == m.end()) continue;
        for (const auto& cell: col->second) {
            res[cell.first][j] = (res[cell.first][j] + (cell.second * (v % MOD)) % MOD) % MOD;
        }
    }
    for (const auto& row: res) {
        for (const auto& cell: row.second) {
            if (cell.second != 0) {
                cout << row.first << ' ' << cell.first << ' ' << cell.second << endl;
            }
        }
    }
    return 0;
}
