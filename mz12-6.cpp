#include <cstdio>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

void f(unsigned n, unsigned i, double v1, unsigned j, double v2, std::vector<double> &accs, std::vector<std::mutex> &accs_mutex) {
    using std::lock, std::lock_guard, std::mutex, std::adopt_lock;
    for (unsigned k = 0; k < n; ++k) {
        lock(accs_mutex[i], accs_mutex[j]);
        lock_guard<mutex> l1(accs_mutex[i], adopt_lock);
        lock_guard<mutex> l2(accs_mutex[j], adopt_lock);
        accs[i] += v1;
        accs[j] += v2;
    }
}

int main() {
    using std::cin, std::cout, std::endl, std::ref;
    using std::vector, std::mutex, std::thread;
    unsigned acc_count, thr_count;
    cin >> acc_count >> thr_count;
    vector<double> accs(acc_count, 0);
    vector<mutex> accs_mutex(acc_count);
    vector<thread> thrs;
    for (unsigned k = 0; k < thr_count; ++k) {
        unsigned n, i, j;
        double v1, v2;
        cin >> n >> i >> v1 >> j >> v2;
        thrs.emplace_back(f, n, i, v1, j, v2, ref(accs), ref(accs_mutex));
    }
    for (thread &x: thrs) {
        x.join();
    }
    for (double v: accs) {
        printf("%.10g\n", v);
    }
    return 0;
}
