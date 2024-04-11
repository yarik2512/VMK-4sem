#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include "mz07-1.cpp"

class Rectangle : public Figure
{
    double w, h;

public:
    double
    get_square() const
    {
        return w * h;
    }

    static Rectangle *
    make(const std::string &s)
    {
        Rectangle *R = new Rectangle;
        sscanf(s.c_str(), "%lf %lf", &R->w, &R->h);
        return R;
    }
};

class Square : public Figure
{
    double a;

public:
    double
    get_square() const
    {
        return a * a;
    }

    static Square *
    make(const std::string &s)
    {
        Square *S = new Square;
        sscanf(s.c_str(), "%lf", &S->a);
        return S;
    }
};

class Circle : public Figure
{
    double r;

public:
    double
    get_square() const
    {
        return M_PI * r * r;
    }

    static Circle *
    make(const std::string &s)
    {
        Circle *C = new Circle;
        sscanf(s.c_str(), "%lf", &C->r);
        return C;
    }
};
