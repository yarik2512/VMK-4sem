#include <iostream>
#include <vector>
#include <algorithm>

int
bit_count(const unsigned &a)
{
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if (a & (1 << i)) {
            ++count;
        }
    }
    return count;
}

bool
cmp(const unsigned &a, const unsigned &b)
{
    return bit_count(a) < bit_count(b);
}

int
main()
{
    using std::cin, std::cout, std::endl, std::vector, std::stable_sort;
    vector<unsigned> v;
    unsigned x;
    while (cin >> x) {
        v.push_back(x);
    }
    stable_sort(v.begin(), v.end(), cmp);
    for (const unsigned &n: v) {
        cout << n << endl;
    }
    return 0;
}
