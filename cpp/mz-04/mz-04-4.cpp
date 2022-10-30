#include <algorithm>
#include <vector>

template <typename I, typename E>
auto myremove(I first_idx, I last_idx, E first_el, E last_el)
{
    std::vector<typename I::value_type> v(first_idx, last_idx);
    std::sort(v.begin(), v.end());
    auto v_it = std::unique(v.begin(), v.end());
    v.erase(v_it, v.end());
    v_it = v.begin();
    while (v_it != v.end() && *v_it < 0) {
        v_it++;
    }

    auto ret_it = first_el;
    typename I::value_type idx{};

    for (auto it_el = first_el; it_el != last_el; it_el++) {
        if (idx == *v_it) {
            v_it++;
        } else {
            *ret_it = std::move(*it_el);
            ret_it++;
        }
        ++idx;
    }
    return ret_it;
}
