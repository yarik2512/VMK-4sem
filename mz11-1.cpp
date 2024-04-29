#include <vector>
#include <cstdint>
#include <iostream>

void process(std::vector<uint64_t> &v, uint32_t s) {
    auto i = v.begin();
    uint32_t j = 0;
    uint64_t sum = 0;
    for (; i < v.end(); ++j, ++i) {
        if (j == s) {
            j = -1;
            i = v.insert(i, sum);
        } else {
            sum += *i;
        }
    }
    if (j == s) {
        v.insert(v.end(), sum);
    }
}
