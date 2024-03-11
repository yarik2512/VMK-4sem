#include <iostream>
#include <string>
#include <cmath>

namespace numbers
{
constexpr size_t BUF_SZ = 38;
class complex
{
    double x = 0, y = 0;

public:
    complex(double re = 0, double im = 0) : x(re), y(im){};
    explicit complex(const std::string &str)
    {
        int comma_index = 0;
        for (int i = 0; i < (int) str.length(); ++i) {
            if (str[i] == ',') {
                comma_index = i;
                break;
            }
        }
        x = stod(str.substr(1, comma_index - 1));
        y = stod(str.substr(comma_index + 1, str.length() - comma_index - 2));
    }
    double
    re() const
    {
        return x;
    }
    double
    im() const
    {
        return y;
    }
    double
    abs2() const
    {
        return x * x + y * y;
    }
    double
    abs() const
    {
        return sqrt(abs2());
    }
    std::string
    to_string() const
    {
        char buf[BUF_SZ];
        snprintf(buf, BUF_SZ, "(%.10g,%.10g)", x, y);
        return buf;
    }
    complex &
    operator+=(const complex &b)
    {
        x += b.x;
        y += b.y;
        return *this;
    }
    complex &
    operator-=(const complex &b)
    {
        x -= b.x;
        y -= b.y;
        return *this;
    }
    complex &
    operator*=(const complex &b)
    {
        double tmp_x = x;
        double tmp_y = y;
        x = tmp_x * b.x - tmp_y * b.y;
        y = tmp_x * b.y + tmp_y * b.x;
        return *this;
    }
    complex &
    operator/=(const complex &b)
    {
        double tmp_x = x;
        double tmp_y = y;
        x = (tmp_x * b.x + tmp_y * b.y) / b.abs2();
        y = (b.x * tmp_y - tmp_x * b.y) / b.abs2();
        return *this;
    }
    complex
    operator~() const
    {
        return {x, -y};
    }
    complex
    operator-() const
    {
        return {-x, -y};
    }
    friend complex operator+(const complex &a, const complex &b);
    friend complex operator-(const complex &a, const complex &b);
    friend complex operator*(const complex &a, const complex &b);
    friend complex operator/(const complex &a, const complex &b);
};
complex
operator+(const complex &a, const complex &b)
{
    complex tmp = a;
    return (tmp += b);
}
complex
operator-(const complex &a, const complex &b)
{
    complex tmp = a;
    return (tmp -= b);
}
complex
operator*(const complex &a, const complex &b)
{
    complex tmp = a;
    return (tmp *= b);
}
complex
operator/(const complex &a, const complex &b)
{
    complex tmp = a;
    return (tmp /= b);
}
}
