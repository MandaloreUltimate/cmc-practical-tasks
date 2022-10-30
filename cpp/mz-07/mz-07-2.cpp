#include <iostream>

/*
Ackermann function
k = 0 - a + b
k = 1 - a * b
k = 2 - a ^ b
k = 3 - a ^ ... ^ a - b times
and so on...
*/

class Result {
private:
    int64_t res_;
public:
    Result(int64_t val) : res_(val) {};

    int64_t res() const {
        return res_;
    }
};

void func(int64_t a, int64_t b, uint32_t k)
{
    if (!k) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
    }

    try {
        func(a, b - 1, k);
    } catch (Result &ans) {
        func(a, ans.res(), k - 1);
    }
}

int main()
{
    int64_t a, b;
    uint32_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch(Result &ans) {
            std::cout << ans.res() << std::endl;
        }
    }
    return 0;
}
