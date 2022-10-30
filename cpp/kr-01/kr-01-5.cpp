#include <string>

class Figure {
public:
    virtual ~Figure();
    virtual bool equals(Figure *) const = 0;
};

class Rectangle : public Figure
{
private:
    int a_, b_;
public:
    Rectangle(int a = 0, int b = 0): a_(a), b_(b) {}
    virtual bool equals(Figure *fig) const override {
        Rectangle &other = dynamic_cast<Rectangle &> (*fig);
        return (a_ == other.a_ && b_ == other.b_);
    }
};

class Triangle : public Figure
{
private:
    int a_, b_, c_;
public:
    Triangle(int a = 0, int b = 0, int c = 0): a_(a), b_(b), c_(c) {}
    virtual bool equals(Figure *fig) const override {
        Triangle &other = dynamic_cast<Triangle &> (*fig);
        return (a_ == other.a_  && b_ == other.b_ && c_ == other.c_);
    }
};
