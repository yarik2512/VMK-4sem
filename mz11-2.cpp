#include <cstddef>

namespace Sample
{
template <typename T, size_t N, size_t M> class Matrix
{
    T m[N][M] = {0};

public:
    T *
    operator[](size_t i)
    {
        return m[i];
    }
    const T *
    operator[](size_t i) const
    {
        return m[i];
    }
};
} // namespace Sample
