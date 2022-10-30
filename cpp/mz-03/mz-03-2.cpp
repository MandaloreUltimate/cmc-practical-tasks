#include <iostream>
#include <vector>

void process(std::vector<int64_t> &v, int64_t border)
{
    size_t add_mem = 0;
    for (int x : v) {
        if (x >= border) {
            add_mem++;
        }
    }
    v.reserve(v.size() + add_mem + 1);
    auto v_ptr = v.rbegin();
    auto v_end = v.rend();

    while (v_ptr != v_end) {
        if (*v_ptr >= border) {
            v.push_back(*v_ptr);
        }
        v_ptr++;
    }
}
