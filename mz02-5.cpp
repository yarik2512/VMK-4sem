#include <iostream>

class Row
{
    int *r;

public:
    Row()
    {
        r = new int[3];
        r[0] = 0, r[1] = 0, r[2] = 0;
    }

    int &
    operator[](int i)
    {
        return r[i];
    }

    int *
    begin() const
    {
        return r;
    }

    int *
    end() const
    {
        return r;
    }

    ~Row() { delete[] r; }
};

class Matrix
{
    Row *m;

public:
    Matrix() { m = new Row[3]; };
    int &
    operator[](int i, int j)
    {
        return m[i][j];
    }
    Row *
    begin()
    {
        return m;
    }
    Row *
    end()
    {
        return &m[2];
    }
    ~Matrix() { delete[] m; }
};

int
main()
{
    using std::cout;
    Matrix m;
    m[1, 1] = 5;

    for (const auto &row : m) {
        for (auto cell : row) {
            cout << 1 << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}
