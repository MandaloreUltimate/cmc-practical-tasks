#include <iostream>
#include <vector>
#include <algorithm>

bool check(std::string str)
{
    std::vector<char> nums{'1', '2', '3', '4'};
    bool beta = false;
    for (const char &c: str) {
        if (std::find(nums.begin(), nums.end(), c) != nums.end()) {
            if (beta && (c == '3' || c == '4')) {
                return false;
            }
            if (c == '1' || c == '2') {
                beta = true;
            }
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
    return 0;
}
