#include <vector>
#include <ranges>

void process(std::vector<long> &v, long threshold) {
    v.reserve(2 * v.size());
    for (long x: v | std::ranges::views::reverse) {
        if (x >= threshold) {
            v.push_back(x);
        }
    }
}
