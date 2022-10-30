#include <iostream>

class A
{
    int sum;
    bool destr = false;
public:
    A(): destr(true) {
        std::cin >> sum;
    }
    A(const A &a) {
        int val;
        std::cin >> val;
        sum = val + a.sum;
    }

    ~A() {
        if (!destr) {
            std::cout << sum << std::endl;
        }
    }
};
