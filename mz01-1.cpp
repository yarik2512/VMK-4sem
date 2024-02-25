class Sum
{
    long long a, b;

public:
    Sum(long long A = 0, long long B = 0) : a(A), b(B){};

    Sum(const Sum &A, long long B = 0) : a(A.get()), b(B){};

    long long
    get() const
    {
        return a + b;
    }
};
