#include <iostream>
#include <string>

class stringObject
{
private:
    std::string str_;
public:
    stringObject(std::string str_val): str_(str_val) {}
    ~stringObject() {
        std::cout << str_ << std::endl;
    }
};

void recursive_print()
{
    std::string str;
    if (std::cin >> str) {
        stringObject s(str);
        recursive_print();
    } else {
        throw 42;
    }
}

int main()
{
    try {
        recursive_print();
    }
    catch (...) {}
    return 0;
}
