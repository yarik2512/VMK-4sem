#include <iostream>

class Result
{
    long long res;

public:
    Result(long long a = 0) : res(a) {}

    operator long long() const {
        return res;
    }

    friend std::ostream &operator<<(std::ostream &out, const Result &r);
};

std::ostream &
operator<<(std::ostream &out, const Result &r)
{
    out << r.res;
    return out;
}

void
f(long long a, long long b, unsigned k) // функция Аккермана
{
    if (k == 0) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
    }
    Result res;
    try {
        f(a, b - 1, k);
    } catch (Result &r) {
        res = r;
    }
    try {
        f(a, res, k - 1);
    } catch (Result &r) {
        throw;
    }
}

int
main()
{
    long long a, b;
    unsigned k;
    while (std::cin >> a >> b >> k) {
        try {
            f(a, b, k);
        } catch (Result &r) {
            std::cout << r << std::endl;
        }
    }
    return 0;
}
