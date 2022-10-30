#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/* Grammar
S -> AB
A -> aAb | ab
B -> CB1 | C1
bC -> Cb
aC -> a0
0C -> 00
*/

bool check(std::string str)
{
    std::vector<char> chars{'a', '0', 'b', '1'};
    std::vector<size_t> sz(4, 0);
    size_t i = 0;
    for (int j = 0; j < 4; j++) {
        for (; i < str.size() && str[i] == chars[j]; ++i, ++sz[j]) {}
    }
    size_t sum = std::accumulate(sz.begin(), sz.end(), 0);
    return (sum == str.length() && sz[0] && sz[1] && (sz[0] == sz[2]) && (sz[1] == sz[3]));
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
    return 0;
}
