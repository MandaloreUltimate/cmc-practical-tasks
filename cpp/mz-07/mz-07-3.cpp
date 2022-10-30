#include <iostream>

class S
{
private:
    int sum_ = 0;
    bool continue_flag;
    bool empty_flag;
public:
    S() : continue_flag(true), empty_flag(true) {
        int val{};
        if (std::cin >> val) {
            empty_flag = false;
            sum_ = val;
        } else {
            continue_flag = false;
        }
    }
    S (S&& other) : continue_flag(true), empty_flag(false) {
        int val{};
        sum_ = other.sum_;
        if (std::cin >> val) {
            sum_ += val;
        } else {
            continue_flag = false;
        }
    }
    ~S() {
        if (!empty_flag && !continue_flag) {
            std::cout << sum_;
        }
    }
    operator bool() const {
        return continue_flag;
    }
};
