#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <set>

int main()
{
    char a;
    std::string b;
    std::set<char> V{'S'};
    bool changed = true;
    std::multimap<char, std::string> gr;
    while (std::cin >> a >> b) {
        gr.insert({a, b});
    }
    while (changed) {
        changed = false;
        for (auto rule: gr) {
            if (V.count(rule.first)) {
                for (auto c: rule.second) {
                    if (isupper(c) && !V.count(c)) {
                        V.insert(c);
                        changed = true;
                    }
                }
            }
        }
    }
    for (auto rule: gr) {
        if (V.count(rule.first)) {
            std::cout << rule.first << " " << rule.second << std::endl;
        }
    }
}
