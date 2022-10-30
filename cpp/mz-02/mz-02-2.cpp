#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

namespace numbers {
    constexpr int START_SIZE = 16;
    class complex_stack {
    private:
        complex *st = nullptr;
        size_t st_size;
        size_t top;
    public:
        complex_stack(): st_size(START_SIZE), top(0) {
            st = new complex[st_size];
        }

        complex_stack(const complex_stack &other)
        {
            st_size = other.st_size;
            top = other.top;
            st = new complex[st_size];
            memcpy(st, other.st, st_size * sizeof(*st));
        }

        ~complex_stack() {
            if (st) {
                delete[] st;
            }
        }

        size_t size() const {
            return top;
        }

        complex operator[](size_t idx) const {
            return st[idx];
        }

        complex_stack operator=(complex_stack other)
        {
            std::swap(st_size, other.st_size);
            std::swap(top, other.top);
            std::swap(st, other.st);
            return *this;
        }

        complex operator+() const {
            return st[top - 1];
        }

        complex_stack operator~() const
        {
            complex_stack other(*this);
            other.top--;
            return other;
        }

        complex_stack operator<<(complex val) const {
            complex_stack other = *this;
            if (top == st_size) {
                other.st_size <<= 1;
                complex *tmp = new complex[other.st_size];
                memcpy(tmp, st, top * sizeof(*tmp));
                delete[] other.st;
                other.st = tmp;
            }
            other.st[other.top++] = val;
            return other;
        }
    };
}
