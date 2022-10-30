#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;
    int r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        int dist1 = std::min(std::abs(r2 - r1), std::abs(std::abs(r2 - r1) - m));
        int dist2 = std::min(std::abs(c2 - c1), std::abs(std::abs(c2 - c1) - n));
        std::cout << dist1 + dist2 << std::endl;
    }
}
