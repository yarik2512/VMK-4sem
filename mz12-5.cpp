#include <cstdio>
#include <array>
#include <mutex>
#include <thread>

constexpr int N = 1000000;
constexpr int S = 3;

std::array<double, S> a = {0, 0, 0};

std::mutex m;

void f(int j, int v) {
    for (int i = 0; i < N; ++i) {
        m.lock();
        a[j] += v;
        a[(j + 1) % S] -= (v + 1);
        m.unlock();
    }
}

int main() {
    std::thread t1(f, 0, 100);
    std::thread t2(f, 1, 200);
    std::thread t3(f, 2, 300);
    t1.join();
    t2.join();
    t3.join();
    for (int i = 0; i < S; ++i) {
        printf("%.10g\n", a[i]);
    }
    return 0;
}
