#include <functional>
#include <vector>

template <typename T, typename F>
void myapply(T first, T last, F f) {
    for (auto it = first; it != last; ++it) {
        f(*it);
    }
}

template <typename T, typename F>
auto myfilter2(T first, T last, F f) {
    std::vector<std::reference_wrapper<typename T::value_type>> res{};
    for (auto it = first; it != last; ++it) {
        if (f(*it)) {
            res.insert(res.end(), (*it));
        }
    }
    return res;
}

template <typename T, typename F>
void myapply(T *first, T *last, F f) {
    for (auto it = first; it != last; ++it) {
        f(*it);
    }
}

template <typename T, typename F>
auto myfilter2(T *first, T *last, F f) {
    std::vector<std::reference_wrapper<T>> res{};
    for (auto it = first; it != last; ++it) {
        if (f(*it)) {
            res.insert(res.end(), (*it));
        }
    }
    return res;
}
