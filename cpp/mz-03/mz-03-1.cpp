#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

void process(const std::vector<uint64_t> &v1, std::vector<uint64_t> &v2, unsigned int step)
{
    auto v1_ptr = v1.begin();
    auto v2_ptr = v2.rbegin();
    auto v2_end = v2.rend();

    size_t v1_size = std::distance(v1.begin(), v1.end());
    size_t j = 0;

    while ((j < v1_size) && (v2_ptr != v2_end)) {
        *v2_ptr += *v1_ptr;
        v2_ptr++;
        j += step;
        v1_ptr += step;
    }
}
