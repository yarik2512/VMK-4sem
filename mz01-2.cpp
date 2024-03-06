#include <iostream>

class A
{
    int a;
    static bool flag;

public:
    A()
    {
        flag = false;
        std::cin >> a;
    }

    A(const A &b)
    {
        flag = false;
        std::cin >> a;
        a += b.a;
    }

    ~A()
    {
        if (!flag) {
            std::cout << a;
            flag = true;
        }
    }
};

bool A::flag;
