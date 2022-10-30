#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    int idx = 0;
    auto v2_it = v2.begin();
    int v2_size = v2.size();
    auto v2_end = v2_it;

    std::vector<int> v_idx(v1);
    std::sort(v_idx.begin(), v_idx.end());
    auto v_idx_it = std::unique(v_idx.begin(), v_idx.end());
    v_idx.erase(v_idx_it, v_idx.end());
    v_idx_it = v_idx.begin();
    while (v_idx_it != v_idx.end() && *v_idx_it < 0) {
        v_idx_it++;
    }

    while ((idx < v2_size) && (v_idx_it != v_idx.end())) {
        if (*v_idx_it != idx) {
            std::swap(*v2_it, *v2_end);
            v2_end++;
            v2_it++;
        } else {
            v_idx_it++;
            v2_end++;
        }
        idx++;
    }

    v2.erase(v2_it, v2_end);
}
