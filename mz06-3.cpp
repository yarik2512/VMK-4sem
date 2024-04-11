#include <vector>
#include <functional>

template <typename I, typename F>
void
myapply(I begin, I end, F f)
{
    for (; begin != end; ++begin) {
        f(*begin);
    }
}

template <typename I, typename F>
std::vector<std::reference_wrapper<typename std::iterator_traits<I>::value_type>>
myfilter2(I begin, I end, F f)
{
    std::vector<std::reference_wrapper<typename std::iterator_traits<I>::value_type>> res;
    for (; begin != end; ++begin) {
        if (f(*begin)) {
            res.insert(res.end(), std::ref(*begin));
        }
    }
    return res;
}
