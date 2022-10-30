#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

constexpr int PREC = 10;

class Sum
{
private:
    double sum_ = 0.0;
public:
    double sum() const {
        return sum_;
    }
    void operator()(const double &val) {
        sum_ += val;
    }
};

void vec_cut(std::vector<double> &vec, int cut) {
    vec.erase(vec.begin(), vec.begin() + cut);
    vec.erase(vec.end() - cut, vec.end());
}

int main()
{
    double val;
    std::vector<double> vec;
    while (std::cin >> val) {
        vec.push_back(val);
    }

    vec_cut(vec, vec.size() / PREC);
    sort(vec.begin(), vec.end());
    vec_cut(vec, vec.size() / PREC);

    Sum ans = for_each(vec.begin(), vec.end(), Sum());
    std::cout << std::fixed << std::setprecision(PREC) << ans.sum() / vec.size() << std::endl;
    return 0;
}
