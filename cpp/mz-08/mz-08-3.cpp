#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>

bool all_T(const std::string& s) {
    return std::all_of(s.begin(), s.end(), [](unsigned char c){ return (std::islower(c) || std::isdigit(c)); });
}

int main()
{
    bool has_S = false;
    bool non_empty = false;
    bool all_term = false;
    bool cf = true;
    bool not_less = true;
    bool right_S = false;
    bool free_S = false;

    std::vector<std::string> rule(2);
    while (std::cin >> rule[0] >> rule[1]) {
        non_empty = true;

        if (all_T(rule[0])) {
            all_term = true;
            break;
        }

        if (strchr(rule[1].c_str(), 'S')) {
            right_S = true;
        }

        if (rule[0] == "S") {
            has_S = true;
        }

        if (rule[0].length() > rule[1].length()) {
            not_less = false;
        }

        if (rule[1] == "_") {
            if (rule[0] == "S") {
                free_S = true;
            } else {
                not_less = false;
            }
        }

        if (rule[0].length() != 1 || all_T(rule[0])) {
            cf = false;
        }
    }

    if (!non_empty || !has_S || all_term) {
        std::cout << -1 << std::endl;
    } else if (cf) {
        std::cout << 2;
        if (not_less && ((free_S && !right_S) || !free_S)) {
            std::cout << 3;
        }
        std::cout << std::endl;
    } else {
        std::cout << 10 << std::endl;
    }
    return 0;
}
