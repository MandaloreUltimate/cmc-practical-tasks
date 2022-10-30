#include <algorithm>

template <class T>
class Coord
{
public:
    typedef T value_type;
    T row;
    T col;
    Coord() {};
    Coord(T x = T(), T y = T()): row(x), col(y) {}
};

template <class T>
T dist(const Coord<T> &rect, const Coord<T> &a, const Coord<T> &b)
{
    if (!rect.row || !rect.col) {
        return T();
    }

    T diff1 = std::min(std::abs(a.row - b.row), -std::abs(a.row - b.row) + rect.row);
    T diff2 = std::min(std::abs(a.col - b.col), -std::abs(a.col - b.col) + rect.col);
    return std::max(diff1, diff2);
}
