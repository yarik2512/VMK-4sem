#include <iostream>
#include <utility>

class c
{
    std::string s;

public:
    c(const std::string &s_) : s(s_){}

    ~c() {
        if (s.empty()) {
            return;
        }
        std::cout << s << std::endl;
    }
};

void
f()
{
    std::string s;
    if (!(std::cin >> s)) {
        throw c(s);
    }
    try {
        f();
    } catch (c &) {
        // catch для того, чтобы вызывался деструктор c, который выводит строку
        throw c(s);
    }
}

int
main()
{
    try {
        f();
    } catch (c &) {
    }
    return 0;
}
