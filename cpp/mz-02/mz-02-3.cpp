#include <vector>
#include <string>
namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex v1, v2;
        complex_stack cur_stack;

        int size = args.size();

        for (int i = 0; i < size; i++) {
            const char *str = args[i].c_str();
            if (str[0] == ';') {
                cur_stack = ~cur_stack;
            } else if (str[0] == '~') {
                v1 = +cur_stack;
                cur_stack = ~cur_stack;
                cur_stack = cur_stack << ~v1;
            } else if (str[0] == 'z') {
                cur_stack = cur_stack << z;
            } else if (str[0] == '(') {
                cur_stack = cur_stack << complex(args[i]);
            } else if (str[0] == '#') {
                v1 = +cur_stack;
                cur_stack = ~cur_stack;
                cur_stack = cur_stack << -v1;
            } else if (str[0] == '!') {
                cur_stack = cur_stack << (+cur_stack);
            } else if (str[0] == '*') {
                v1 = +cur_stack;
                cur_stack = ~cur_stack;
                v2 = +cur_stack;
                cur_stack = ~cur_stack;
                cur_stack = cur_stack << (v1 * v2);
            } else if (str[0] == '-') {
                v1 = +cur_stack;
                cur_stack = ~cur_stack;
                v2 = +cur_stack;
                cur_stack = ~cur_stack;
                cur_stack = cur_stack << (v2 - v1);
            } else if (str[0] == '/') {
                v1 = +cur_stack;
                cur_stack = ~cur_stack;
                v2 = +cur_stack;
                cur_stack = ~cur_stack;
                cur_stack = cur_stack << (v2 / v1);
            } else if (str[0] == '+') {
                v1 = +cur_stack;
                cur_stack = ~cur_stack;
                v2 = +cur_stack;
                cur_stack = ~cur_stack;
                cur_stack = cur_stack << (v1 + v2);
            }
        }
        return +cur_stack;
    }
}
