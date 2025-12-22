#include <iostream>
#include <thread>
#include <future>
#include <exception>
#include <vector>

void f(uint64_t low, uint64_t high, uint32_t count, std::vector<std::promise<uint64_t>> res) {
    uint32_t j = 0;
    for (uint64_t num = low; num <= high && j < count; ++num) {
        if (num < 2) {
            continue;
        }
        bool p = true;
        for (uint64_t i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                p = false;
                break;
            }
        }
        if (p) {
            res[j].set_value(num);
            ++j;
        }
    }
    if (j < count) {
        res[j].set_exception(std::make_exception_ptr(high));
    }
}

int main() {
    uint64_t low, high;
    uint32_t count;
    std::cin >> low >> high >> count;
    std::vector<std::promise<uint64_t>> prom(count);
    std::vector<std::future<uint64_t>> fut(count);
    for (uint32_t i = 0; i < count; ++i) {
        fut[i] = prom[i].get_future();
    }
    std::thread t(f, low, high, count, std::move(prom));
    for (uint32_t i = 0; i < count; ++i) {
        try {
            std::cout << fut[i].get() << std::endl;
        } catch (uint64_t e) {
            std::cout << e << std::endl;
            break;
        }
    }
    t.join();
    return 0;
}
