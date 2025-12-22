#include <iostream>
#include <iomanip>
#include <thread>
#include <future>
#include <sstream>
#include <vector>

constexpr double EPS = 1e-6;

std::pair<uint64_t, uint64_t> pi(uint64_t n) {
    uint32_t tid = std::hash<std::thread::id>{}(std::this_thread::get_id());
    uint64_t count = 0;
    double R = (double) RAND_MAX / 2;
    for (uint64_t i = 0; i < n; ++i) {
        double x = (double) rand_r(&tid) - R;
        double y = (double) rand_r(&tid) - R;
        if (x * x + y * y - R * R < EPS) {
            ++count;
        }
    }
    return {count, n};
}

int main(int argc, char *argv[]) {
    std::stringstream s1(argv[1]);
    uint64_t thr_cnt;
    s1 >> thr_cnt;
    std::stringstream s2(argv[2]);
    uint64_t n;
    s2 >> n;
    std::vector<std::future<std::pair<uint64_t, uint64_t>>> fut;
    for (uint64_t i = 0; i < thr_cnt; ++i) {
        fut.push_back(std::async(std::launch::async, pi, n));
    }
    double sum = 0;
    for (uint64_t i = 0; i < thr_cnt; ++i) {
        std::pair<uint64_t, uint64_t> res = fut[i].get();
        sum += 4 * (double) res.first / (double) res.second;
    }
    std::cout << std::setprecision(6) << sum / (double) thr_cnt << std::endl;
    return 0;
}
