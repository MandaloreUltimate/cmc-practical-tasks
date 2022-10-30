#include <iostream>

/*
S -> aSd | aAd
A -> bAc | bc
*/

void gen_str(size_t m, size_t n) {
    if (m > 0) {
        std::cout << "a";
        gen_str(m - 1, n);
        std::cout << "d";
    } else {
        std::cout << "b";
        if (n > 1) {
            gen_str(0, n - 1);
        }
        std::cout << "c";
    }
}

void rec_print(size_t m, size_t n)
{
    if (!m) {
        return;
    }
    for (; m > 0; m--, n++) {
        gen_str(m, n);
        std::cout << std::endl;
    }
    return;
}

int main()
{
    int k;
    std::cin >> k;
    if (k >= 4 && !(k % 2)) {
        rec_print(k / 2 - 1, 1);
    }
    return 0;
}
