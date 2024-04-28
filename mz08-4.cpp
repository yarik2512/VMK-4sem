#include <complex>
#include <vector>
#include <array>
#include <limits>

namespace Equations {
constexpr int SZ = 3;
constexpr int MUL = 32;
constexpr double C1 = 4.0;
constexpr double C2 = 2.0;

template<typename T>
bool null(const std::complex<T> &z) {
    return std::norm(z) < MUL * std::numeric_limits<T>::epsilon();
}

template<typename T>
std::pair<bool, std::vector<std::complex<T>>> quadratic(const std::array<std::complex<T>, SZ> &v) {
    std::complex<T> a = v[2], b = v[1], c = v[0];
    if (null(a)) {
        if (null(c)) {
            if (null(b)) return {false, {}};
            return {true, {std::complex<T>(0)}};
        }
        if (null(b)) return {true, {}};
        return {true, {-c / b}};
    }
    std::complex<T> c4(C1);
    std::complex<T> c2(C2);
    std::complex<T> D = b * b - c4 * a * c;
    return {true, {(-b + std::sqrt(D)) / (c2 * a), (-b - std::sqrt(D)) / (c2 * a)}};
}
}
