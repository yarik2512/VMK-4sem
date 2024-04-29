#include <iostream>

class DKA
{
    static char c;

    struct State
    {
        virtual State *operator()() = 0;
        virtual ~State() = default;
    };

    struct ERR : State
    {
        State *
        operator()() override
        {
            return new ERR();
        }
    };

    struct S : State
    {
        State *
        operator()() override
        {
            switch (c) {
            case 'a':
                return new A();
            case 'b':
                return new B();
            default:
                return new ERR();
            }
        }
    };

    struct A : State
    {
        State *
        operator()() override
        {
            switch (c) {
            case 'a':
                return new S();
            case 'b':
                return new E();
            case 'c':
                return new C();
            default:
                return new ERR();
            }
        }
    };

    struct B : State
    {
        State *
        operator()() override
        {
            switch (c) {
            case 'a':
                return new S();
            default:
                return new ERR();
            }
        }
    };

    struct C : State
    {
        State *
        operator()() override
        {
            switch (c) {
            case 'a':
                return new D();
            case 'b':
                return new B();
            default:
                return new ERR();
            }
        }
    };

    struct D : State
    {
        State *
        operator()() override
        {
            switch (c) {
            case 'a':
                return new A();
            case 'b':
                return new B();
            default:
                return new ERR();
            }
        }
    };

    struct E : State
    {
        State *operator()() override {
            return new ERR();
        }
    };

    State *cur, *next;

public:
    bool gc() {
        for (std::cin >> c; !std::cin.eof() && isspace(c); std::cin >> c);
        return !std::cin.eof();
    }

    void analyze() {
        cur = new S();
        while (gc() && !(dynamic_cast<ERR *>(cur))) {
            next = (*cur)();
            delete cur;
            cur = next;
        }
        if (!std::cin.eof() || (typeid(*cur) != typeid(D) && typeid(*cur) != typeid(E))) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
};

char DKA::c;

int main() {
    DKA D{};
    D.analyze();
    return 0;
}
