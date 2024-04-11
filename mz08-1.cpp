#include <iostream>
#include <utility>

class c
{
    std::string s;

public:
    c(std::string s_) : s(std::move(s_)){}

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
