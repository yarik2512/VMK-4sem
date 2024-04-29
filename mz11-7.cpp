#include <iostream>
#include <cstdint>

std::string gen_power(uint32_t power) {
    if (power == 0) {
        return "1";
    }
    if (power & 1) {
        return gen_power(power - 1) + "x*";
    }
    return gen_power(power / 2) + "!*";
}
