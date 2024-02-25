#include <iostream>
#include <cmath>
#include <iomanip>

int
main()
{
    using std::cout, std::cin, std::setprecision, std::endl;
    int n = 0;
    double cur;
    double sum = 0, sq_sum = 0;
    while (cin >> cur) {
        sum += cur;
        sq_sum += cur * cur;
        n++;
    }
    double avg = sum / n;
    double st_dev = sqrt((sq_sum - 2 * sum * avg + n * avg * avg) / n);
    cout << setprecision(10) << avg << endl << st_dev << endl;
    return 0;
}
