#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

constexpr double EPS = 1e-12;

void
solve_integral(numbers::complex &I, const numbers::complex &C, double R, int N, const std::vector<std::string> &func)
{
    I = numbers::complex(0, 0);
    double phi, re, im, cos_p, sin_p;
    for (int i = 0; i < N; ++i) {
        phi = double(i) * 2 * M_PI / double(N);
        cos_p = std::cos(phi);
        sin_p = std::sin(phi);
        re = R * cos_p;
        im = R * sin_p;
        numbers::complex z(re, im);
        numbers::complex f = numbers::eval(func, z + C);
        I += {-f.re() * sin_p - f.im() * cos_p, f.re() * cos_p - f.im() * sin_p};
    }
    I *= 2 * M_PI * R / double(N);
}

int
main(int argc, char *argv[])
{
    numbers::complex C(argv[1]);
    double R = std::stod(argv[2]);
    int N = std::stoi(argv[3]);
    std::vector<std::string> func;
    for (int i = 4; i < argc; ++i) {
        func.emplace_back(argv[i]);
    }
    numbers::complex I;
    solve_integral(I, C, R, N, func);
    std::cout << I.to_string() << std::endl;
    return 0;
}
