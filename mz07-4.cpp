#include <algorithm>

namespace Game {
template<typename T>
struct Coord {
    typedef T value_type;
    value_type col, row;

    Coord(value_type c = 0, value_type r = 0) : col(c), row(r) {}
};

template<typename T>
T dist(const Coord<T> &sz, const Coord<T> &a, const Coord<T> &b) {
    T aq = a.col - (a.row + (a.row & 1)) / 2;
    T ar = a.row;
    T bq = b.col - (b.row + (b.row & 1)) / 2;
    T br = b.row;
    return std::max({std::abs(aq - bq), std::abs(ar - br), std::abs(-aq - ar + bq + br)});
}
}
