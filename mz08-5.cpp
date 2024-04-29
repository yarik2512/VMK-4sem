#include <iostream>
#include <chrono>
#include <iomanip>

int
main()
{
    using std::mktime, std::tm, std::get_time;
    using std::string, std::stringstream, std::cin, std::cout, std::endl;
    using std::chrono::time_point, std::chrono::system_clock, std::chrono::duration_cast, std::chrono::days,
        std::chrono::abs;
    tm tm_buf{};
    cin >> get_time(&tm_buf, "%Y-%m-%d");
    time_point<system_clock> prev = system_clock::from_time_t(mktime(&tm_buf));
    time_point<system_clock> cur;
    long sum{};
    while (cin >> get_time(&tm_buf, "%Y-%m-%d")) {
        cur = system_clock::from_time_t(mktime(&tm_buf));
        auto dur = duration_cast<days>(abs(cur - prev));
        sum += dur.count();
        prev = cur;
    }
    cout << sum << endl;
    return 0;
}
