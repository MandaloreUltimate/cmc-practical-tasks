#include <iostream>

namespace Sample {
    template <typename T, size_t rows, size_t cols>
    class Matrix {
        T mat[rows][cols];
    public:
        const T* operator [] (size_t i) const {
            return mat[i];
        }
        T* operator [] (size_t i) {
            return mat[i];
        }
    };
}
