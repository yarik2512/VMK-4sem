#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

struct Sum
{
    double sum = 0;
    void
    operator()(double x)
    {
        sum += x;
    }
};

double
avg(const std::vector<double> &res)
{
    long count = (long) res.size() / 10;
    std::vector<double> v(res.begin() + count, res.end() - count);
    count = (long) v.size() / 10;
    std::sort(v.begin(), v.end());
    v.erase(v.begin(), v.begin() + count);
    v.erase(v.end() - count, v.end());
    double sum = std::for_each(v.begin(), v.end(), Sum()).sum;
    return sum / (double) v.size();
}

int
main()
{
    std::vector<double> v;
    double d;
    while (std::cin >> d) {
        v.push_back(d);
    }
    std::cout << std::setprecision(10) << avg(v) << std::endl;
    return 0;
}
