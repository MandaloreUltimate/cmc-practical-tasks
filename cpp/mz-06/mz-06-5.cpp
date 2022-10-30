#include <vector>
#include <utility>
#include <complex>
#include <array>
#include <iostream>

namespace Equations
{
    constexpr int SIZE = 3;
    template <typename T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, SIZE> &arr)
    {
        std::pair<bool, std::vector<std::complex<T>>> res;
        res.first = true;
        auto a = arr[2], b = arr[1], c = arr[0];
        const std::complex<T> _NULL(0,0);

        if (a == _NULL) {
            if (b == _NULL) {
                if (c == _NULL) {
                    res.first =  false;
                    return res;
                }
                return res;
            }
            res.second.push_back(-c / b);
            return res;
        } else {
            auto D = std::sqrt(b * b - T(4.0) * a * c);
            auto x_1 = (-b - D) / (T(2.0) * a);
            auto x_2 = (-b + D) / (T(2.0) * a);
            res.second.push_back(x_1);
            res.second.push_back(x_2);
            return res;
        }
    }
}
