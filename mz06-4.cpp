#include <algorithm>
#include <vector>

template <typename I_n, typename I_el>
I_el
myremove(I_n n_begin, I_n n_end, I_el el_begin, I_el el_end)
{
    int d = std::distance(el_begin, el_end);
    std::vector<int> erase(d, 0);
    for (; n_begin != n_end; ++n_begin) {
        if (*n_begin >= 0 && *n_begin < d) {
            erase[*n_begin] = 1;
        }
    }
    I_el new_end = el_begin;
    for (int i = 0; el_begin != el_end; ++el_begin, ++i) {
        if (!erase[i]) {
            *new_end = std::move(*el_begin);
            ++new_end;
        }
    }
    return new_end;
}
