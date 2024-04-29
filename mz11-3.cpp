#include <functional>
#include <cstdint>

void
calc_binom(int m, int k, std::function<void(uint64_t)> cb)
{
    if (cb) {
        try {
            calc_binom(m, k, {});
        } catch (uint64_t res) {
            cb(res);
        }
    } else {
        if (k > m / 2) {
            k = m - k;
        }
        if (k == 1) {
            throw (uint64_t) m;
        }
        if (k == 0) {
            throw (uint64_t) 1;
        }
        uint64_t b1{}, b2{};
        try {
            calc_binom(m - 1, k, {});
        } catch (uint64_t b) {
            b1 = b;
        }
        try {
            calc_binom(m - 1, k - 1, {});
        } catch (uint64_t b) {
            b2 = b;
        }
        throw b1 + b2;
    }
}
