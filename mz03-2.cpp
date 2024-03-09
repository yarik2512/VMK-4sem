#include <iostream>
#include <string>
#include <cmath>

namespace numbers
{
class complex
{
    double x, y;

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
        char buf[40];
        snprintf(buf, 40, "(%.10g,%.10g)", x, y);
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

class complex_stack
{
    size_t sz;
    complex *data;

public:
    complex_stack() : sz(0), data(nullptr){};
    complex_stack(const complex_stack &b) : sz(b.sz)
    {
        data = new complex[sz];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = b.data[i];
        }
    }
    complex_stack(size_t size, const complex *arr) : sz(size)
    {
        data = new complex[sz];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = arr[i];
        }
    }
    complex_stack(const complex &a, const complex_stack &b) : sz(b.sz + 1)
    {
        data = new complex[sz];
        for (size_t i = 0; i < sz - 1; ++i) {
            data[i] = b.data[i];
        }
        data[sz - 1] = a;
    }
    size_t
    size() const
    {
        return sz;
    }
    complex
    operator[](size_t i) const
    {
        return data[i];
    }
    complex &
    operator+() const
    {
        return data[sz - 1];
    }
    complex_stack &
    operator=(const complex_stack &a)
    {
        if (this == &a) {
            return *this;
        }
        if (sz > 0) {
            delete[] data;
        }
        sz = a.sz;
        data = new complex[sz];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = a.data[i];
        }
        return *this;
    }
    complex_stack
    operator~() const
    {
        return {sz - 1, data};
    }
    complex_stack
    operator<<(const complex &a) const
    {
        return {a, *this};
    }
    ~complex_stack()
    {
        if (sz > 0) {
            delete[] data;
        }
    }
};
} // namespace numbers

int
main()
{
    using numbers::complex_stack, numbers::complex, std::cout, std::endl, std::string;
    complex_stack a;
    a = a;
    complex_stack b(a);
    b = a << complex(1, 1) << 2 << 3;
    b = ~b;
    b = ~b << complex(4, -1) << 5;
    b = b;
    b = (b << 1);
    size_t sz = b.size();
    for (size_t i = 0; i < sz; ++i) {
        cout << (+b).to_string() << endl;
        b = ~b;
    }
    return 0;
}
