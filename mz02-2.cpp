class C
{
    int d;

public:
    C() : d(0){};
    C(int a, int b = 0) : d((int) a + b){};
    C(const C &a) : d(a.d){};
    C(const C *a) : d(a->d){};
    friend int operator+(int a, const C &b);
    int operator~() const;
    const C& operator++();
    operator int() const;
    friend int operator*(const C &a, const C *b);
};

int
operator+(int a, const C &b)
{
    return a + b.d;
}

int
C::operator~() const
{
    return ~d;
}

const C&
C::operator++()
{
    d++;
    return *this;
}

C::operator int() const { return d; }

int
operator*(const C &a, const C *b)
{
    return a.d * b[0].d;
}
