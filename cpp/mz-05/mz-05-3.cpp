#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <memory>

class Factory
{
private:
    Factory() {};
public:
    static Factory &factory_instance(void)
    {
        static Factory f;
        return f;
    }
    std::unique_ptr<Figure> make(const std::string &str) const
    {
        char id;
        std::string params;
        std::istringstream strin(str);
        strin >> id;
        std::getline(strin, params);

        switch(id) {
        case 'R':
            return std::unique_ptr<Figure>(Rectangle::make(params));
        case 'S':
            return std::unique_ptr<Figure>(Square::make(params));
        case 'C':
            return std::unique_ptr<Figure>(Circle::make(params));
        default:
            return nullptr;
        }
    }
};

bool comp(const std::unique_ptr<Figure> &fig1, const std::unique_ptr<Figure> &fig2)
{
    return (fig1->get_square() < fig2->get_square());
}

int main(void)
{
    Factory f{Factory::factory_instance()};
    std::string str;
    std::vector<std::unique_ptr<Figure>> v;
    while (std::getline(std::cin, str)) {
        v.push_back(f.make(str));
    }
    stable_sort(v.begin(), v.end(), comp);
    for (const auto &fig : v) {
        std::cout << fig->to_string() << std::endl;
    }
    v.clear();
    return 0;
}
