#include <iostream>
#include <functional>
#include <vector>

void calc_binom(int m, int k, std::function<void (uint64_t)> cb) {
    if (cb) {
        try {
            calc_binom(m, k, 0);
        } catch (uint64_t & r) {
            cb(r);
        }
    } else {
        std::vector<uint64_t> res(2, 0);
        if (!k) throw static_cast<uint64_t>(1);
        if (k > m) throw static_cast<uint64_t>(0);
        for (int i = 0; i < 2; ++i) {
            try {
                calc_binom(m - 1, k - i, 0);
            } catch (uint64_t & r) {
                res[i] = r;
            }
        }
        throw res[0] + res[1];
    }
}
