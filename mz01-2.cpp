#include <iostream>

class A
{
    int a;

public:
    static bool flag;

    A() { std::cin >> a; }

    A(const A &b)
    {
        std::cin >> a;
        a += b.get();
    }

    int
    get() const
    {
        return a;
    }

    ~A()
    {
        if (!flag) {
            std::cout << a;
            flag = true;
        }
    }
};

bool A::flag = false;
