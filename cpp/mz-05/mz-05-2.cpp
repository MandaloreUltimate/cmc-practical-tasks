#include <string>
#include <sstream>
#include <cmath>

class Rectangle : public Figure
{
private:
    double a_, b_;
public:
    Rectangle(double a = 0.0, double b = 0.0): a_(a), b_(b) {}
    virtual double get_square() const {
        return a_ * b_;
    }
    static Rectangle* make(const std::string &s)
    {
        double a, b;
        std::istringstream str_in(s);
        str_in >> a >> b;
        Rectangle *fig = new Rectangle(a, b);
        return fig;
    }
};

class Square : public Figure
{
private:
    double a_;
public:
    Square(double a = 0.0): a_(a) {}
    virtual double get_square() const {
        return a_ * a_;
    }
    static Square* make(const std::string &s)
    {
        double a;
        std::istringstream strin(s);
        strin >> a;
        Square *fig = new Square(a);
        return fig;
    }
};

class Circle : public Figure
{
private:
    double rad_;
public:
    Circle(double rad = 0.0): rad_(rad) {}
    virtual double get_square() const {
        return M_PI * rad_ * rad_;
    }
    static Circle* make(const std::string &s)
    {
        double rad;
        std::istringstream strin(s);
        strin >> rad;
        Circle *fig = new Circle(rad);
        return fig;
    }
};
