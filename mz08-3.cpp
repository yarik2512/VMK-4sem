#include <iostream>

class S
{
    int a = 0;
    bool end = false, out = false;

public:
    S()
    {
        int c = 0;
        if (!(std::cin >> c)) {
            c = 0;
            end = true;
        } else {
            out = true;
        }
        a += c;
    }

    ~S()
    {
        if (out) {
            std::cout << a;
        }
    }

    operator bool() const { return end; }
};

using namespace std;
void func(S v)
{
    if (v) {
        func(move(v));
    }
}

int main()
{
    func(S());
}
