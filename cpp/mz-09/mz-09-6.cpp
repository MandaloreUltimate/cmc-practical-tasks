#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

int main()
{
    std::map<std::string, std::map<char, std::string>> dfa;
    std::string cur_state, next_state, word;
    char c;
    for (;;) {
        std::cin >> cur_state;
        if (cur_state == "END") {
            break;
        }
        std::cin >> c >> next_state;
        dfa[std::move(cur_state)][c] = std::move(next_state);
    }
    std::set<std::string> final_states;
    for (;;) {
        std::cin >> cur_state;
        if (cur_state == "END") {
            break;
        }
        final_states.insert(cur_state);
    }
    size_t cnt = 0;
    bool flag = true;
    std::cin >> cur_state >> word;
    for (auto it : word) {
        if (dfa[cur_state].count(it)) {
            cur_state = dfa[cur_state][it];
            cnt++;
        } else {
            flag = false;
            break;
        }
    }
    std::cout << (flag && final_states.count(cur_state)) << std::endl << cnt << std::endl << cur_state << std::endl;

    return 0;
}
