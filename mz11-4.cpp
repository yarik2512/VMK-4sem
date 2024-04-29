#include <typeinfo>

class Figure
{
public:
    virtual bool equals(const Figure *f) const = 0;
    virtual ~Figure(){};
};

class Rectangle : public Figure
{
    int a, b;

public:
    Rectangle(int a_, int b_) : a(a_), b(b_) {}

    bool
    equals(const Figure *f) const
    {
        if (!f) {
            return false;
        }
        if (typeid(*this) != typeid(*f)) {
            return false;
        }
        const Rectangle *r = dynamic_cast<const Rectangle *>(f);
        return a == r->a && b == r->b;
    }
};

class Triangle : public Figure
{
    int a, b, c;

public:
    Triangle(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}

    bool
    equals(const Figure *f) const
    {
        if (!f) {
            return false;
        }
        if (typeid(*this) != typeid(*f)) {
            return false;
        }
        const Triangle *t = dynamic_cast<const Triangle *>(f);
        return a == t->a && b == t->b && c == t->c;
    }
};
