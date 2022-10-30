template <typename T, typename F>
auto myfilter(const T &v, F func)
{
    T v2;
    for (auto it : v) {
        if (func(it)) {
            v2.insert(v2.end(), it);
        }
    }
    return v2;
}
