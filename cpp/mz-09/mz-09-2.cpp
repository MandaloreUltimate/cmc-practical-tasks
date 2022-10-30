#include <iostream>

enum {H, A, AB, AC, AS, ABC, ACS, ABS, ABCS, ER, S};
int CS;
char c;
std::string::iterator it;

void gc()
{
    c = *(++it);
}

void func(int v1, int v2)
{
    switch (c) {
    case '0':
        gc();
        CS = v1;
        break;
    case '1':
        gc();
        CS = v2;
        break;
    case '_':
        if (CS == AS || CS == ABS || CS == ACS || CS == ABCS) {
            CS = S;
        } else {
            CS = ER;
        }
        break;
    default:
        CS = ER;
        break;
    }
}

bool scan(std::string str)
{
    CS = H;
    it = str.begin() - 1;
    gc();
    do {
        switch (CS) {
        case H:
        case A:
            func(A, AB);
            break;
        case AB:
            func(AC, ABC);
            break;
        case AC:
            func(AS, ABS);
            break;
        case ABC:
        case ABCS:
            func(ACS, ABCS);
            break;
        case AS:
            func(A, AB);
            break;
        case ACS:
            func(AS, ABS);
            break;
        case ABS:
            func(AC, ABC);
            break;
        default:
            break;
        }
    } while (CS != S && CS != ER);
    return CS == S;
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        str.push_back('_');
        std::cout << scan(str) << std::endl;
    }
    return 0;
}
