#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    double sum = 0;
    double sq_sum = 0;
    int total = 0;
    double num;
    while (std::cin >> num) {
        total++;
        sum += num;
        sq_sum += num * num;
    }
    double average = sum / total;
    double sq_average = sq_sum / total;
    double deviation = sqrt(sq_average - average * average);
    std::cout << std::setprecision(10) << average << std::endl << deviation << std::endl;
    return 0;
}
