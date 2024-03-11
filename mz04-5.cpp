#include <iostream>
#include <list>

int main() {
    std::list<unsigned> l;
    unsigned x;
    while (std::cin >> x) {
        if (x == 0) {
            break;
        }
        l.push_back(x);
    }
    int n;
    while (std::cin >> n) {
        if (n < 0) {
            n = -n - 1;
            if (n >= (int) l.size()) {
                continue;
            }
            std::list<unsigned>::iterator i = l.begin();
            for (; n > 0; --n) {
                ++i;
            }
            l.erase(i);
        } else {
            std::cin >> x;
            --n;
            if (n >= (int) l.size()) {
                l.insert(l.end(), x);
                continue;
            }
            std::list<unsigned>::iterator i = l.begin();
            for (; n > 0; --n) {
                ++i;
            }
            l.insert(i, x);
        }
    }
    for (unsigned int a: l) {
        std::cout << a << std::endl;
    }
    return 0;
}
