template <typename T>
typename T::value_type
process(const T &a)
{
    typename T::const_reverse_iterator it = a.rbegin();
    typename T::value_type sum = typename T::value_type();
    for (int i = 0; i < 3 && it != a.rend(); ++i) {
        sum += *it;
        for (int j = 0; j < 2 && it != a.rend(); ++j, ++it);
    }
    return sum;
}
