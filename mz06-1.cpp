constexpr int COUNT = 3;
constexpr int SHIFT = 2;

template <typename T>
typename T::value_type
process(const T &a)
{
    typename T::const_reverse_iterator it = a.rbegin();
    typename T::value_type sum = typename T::value_type();
    for (int i = 0; i < COUNT && it != a.rend(); ++i) {
        sum += *it;
        for (int j = 0; j < SHIFT && it != a.rend(); ++j, ++it);
    }
    return sum;
}