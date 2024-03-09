#include <vector>
#include <map>
#include <functional>

namespace numbers
{
void
sum(complex_stack &a)
{
    complex z2 = +a;
    a = ~a;
    complex z1 = +a;
    a = ~a;
    a = a << (z1 + z2);
}

void
diff(complex_stack &a)
{
    complex z2 = +a;
    a = ~a;
    complex z1 = +a;
    a = ~a;
    a = a << (z1 - z2);
}

void
mul(complex_stack &a)
{
    complex z2 = +a;
    a = ~a;
    complex z1 = +a;
    a = ~a;
    a = a << (z1 * z2);
}

void
div(complex_stack &a)
{
    complex z2 = +a;
    a = ~a;
    complex z1 = +a;
    a = ~a;
    a = a << (z1 / z2);
}

void
dup(complex_stack &a)
{
    a = a << (+a);
}

void
pop(complex_stack &a)
{
    a = ~a;
}

void
conj(complex_stack &a)
{
    a = (~a) << (~(+a));
}

void
inv(complex_stack &a)
{
    a = (~a) << (-(+a));
}

complex
eval(const std::vector<std::string> &args, const complex &z)
{
    complex_stack s;
    std::map<std::string, std::function<void(complex_stack &)>> ops = {
        {"+", sum}, {"-", diff}, {"*", mul}, {"/", div}, {"!", dup}, {";", pop}, {"~", conj}, {"#", inv}};
    for (const std::string &cmd : args) {
        if (cmd == "z") {
            s = s << z;
        } else if (ops.contains(cmd)) {
            ops[cmd](s);
        } else {
            s = s << complex(cmd);
        }
    }
    return +s;
}
}
