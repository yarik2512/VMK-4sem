#include <vector>
#include <map>
#include <functional>

namespace numbers
{
std::map<std::string, std::function<void(complex_stack &)>> ops = {
    {"+",
     [](complex_stack &a) {
         complex z2 = +a;
         a = ~a;
         complex z1 = +a;
         a = ~a;
         a = a << (z1 + z2);
     }},
    {"-",
     [](complex_stack &a) {
         complex z2 = +a;
         a = ~a;
         complex z1 = +a;
         a = ~a;
         a = a << (z1 - z2);
     }},
    {"*",
     [](complex_stack &a) {
         complex z2 = +a;
         a = ~a;
         complex z1 = +a;
         a = ~a;
         a = a << (z1 * z2);
     }},
    {"/",
     [](complex_stack &a) {
         complex z2 = +a;
         a = ~a;
         complex z1 = +a;
         a = ~a;
         a = a << (z1 / z2);
     }},
    {"!", [](complex_stack &a) { a = a << (+a); }},
    {";", [](complex_stack &a) { a = ~a; }},
    {"~", [](complex_stack &a) { a = (~a) << (~(+a)); }},
    {"#", [](complex_stack &a) { a = (~a) << (-(+a)); }}};

complex
eval(const std::vector<std::string> &args, const complex &z)
{
    complex_stack s;
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
