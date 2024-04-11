#include <functional>

template <typename I, typename F = std::less<>>
void
selection_sort(I begin, I end, F cmp = std::less<>())
{
    for (I i = begin; i < end; ++i) {
        I min = i;
        for (I j = i + 1; j < end; ++j) {
            if (cmp(*j, *min)) {
                min = j;
            }
        }
        if (i != min) {
            std::iter_swap(i, min);
        }
    }
}
