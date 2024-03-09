namespace numbers
{
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
}
