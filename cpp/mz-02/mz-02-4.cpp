#include <iostream>
#include <cmc_complex.h>
#include <cmc_complex_stack.h>
#include <cmc_complex_eval.h>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    numbers::complex center(argv[1]), res(0);
    double rad;
    sscanf(argv[2], "%lf", &rad);
    int n;
    sscanf(argv[3], "%d", &n);
    std::vector<std::string> func;
    for (int i = 4; argv[i] != NULL; i++) {
        func.push_back(std::string(argv[i]));
    }
    double phi = 2 * M_PI / n;

    for (long i = 0; i < n; i++) {
        numbers::complex x(center.re() + rad * cos(phi * i), center.im() + rad * sin(phi * i));
        numbers::complex y(center.re() + rad * cos(phi * (i + 1)), center.im() + rad * sin(phi * (i + 1)));
        res = res + eval(func, (x + y) / 2) * (x - y);
    }

    std::cout << std::setprecision(10) << "(" << res.re() << "," << res.im() << ")" << std::endl;
    return 0;
}
