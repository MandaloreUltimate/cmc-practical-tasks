template <typename T>

auto process(const T &obj)
{
    constexpr int LIMIT = 6;
    typename T::value_type sum{};
    int i = 0;
    for (auto it = obj.rbegin(); it != obj.rend() && i < LIMIT; it++, i++) {
        if (i % 2 == 0) {
            sum += *it;
        }
    }
    return sum;
}
