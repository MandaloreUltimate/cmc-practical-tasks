#include <algorithm>
#include <iostream>

namespace Game
{
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
        T dy = std::abs(a.col - b.col);
        T dx = a.row - b.row;
        T diff = dy / 2;
        if ((dx < 0 && !(a.col % 2)) || (dx > 0 && a.col % 2)) {
            diff += dy % 2;
        }
        return std::abs(dx) + dy - std::min(diff, std::abs(dx));
    }
}
