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
    Rectangle(int a_ = 0, int b_ = 0) : a(a_), b(b_){};

    bool
    equals(const Figure *f) const
    {
        const Rectangle *f_r = dynamic_cast<const Rectangle *>(f);
        if (f_r == nullptr) {
            return false;
        }
        return a == f_r->a && b == f_r->b;
    }
};

class Triangle : public Figure
{
    int a, b, c;

public:
    Triangle(int a_ = 0, int b_ = 0, int c_ = 0) : a(a_), b(b_), c(c_){};

    bool
    equals(const Figure *f) const
    {
        const Triangle *f_t = dynamic_cast<const Triangle *>(f);
        if (f_t == nullptr) {
            return false;
        }
        return a == f_t->a && b == f_t->b && c == f_t->c;
    }
};
