template<typename T, typename P>
T myfilter(T a, P f) {
    T res;
    for (const typename T::value_type &x: a) {
        if (f(x)) {
            res.insert(res.end(), x);
        }
    }
    return res;
}
