#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

// 抽象类，作为接口使用
class Figure
{
public:
    // 纯虚函数
    virtual void display() = 0;
    virtual double area() = 0;
};

class Rectangle
    : public Figure
{
public:
    Rectangle(double length = 0, double width = 0)
        : _length(length), _width(width)
    {
        cout << "Rectangle(double =0,double=0)" << endl;
    }

    void display() override
    {
        cout << "Rectangle";
    }

    double area() override
    {
        return _length * _width;
    }

    ~Rectangle()
    {
        cout << "~Rectangle()" << endl;
    }

private:
    double _length;
    double _width;
};

class Circle
    : public Figure
{
public:
    Circle(double radius = 0)
        : _radius(radius)
    {
        cout << "Circle(double =0)" << endl;
    }

    void display() override
    {
        cout << "Circle";
    }

    double area() override
    {
        return 3.14 * _radius * _radius;
    }

    ~Circle()
    {
        cout << "~Circle()" << endl;
    }

private:
    double _radius;
};

class Triangle
    : public Figure
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
        : _a(a), _b(b), _c(c)
    {
        cout << "Triangle(double a=0,double b=0,double c=0)" << endl;
    }

    void display() override
    {
        cout << "Triangle";
    }

    double area() override
    {
        double t = (_a + _b + _c) / 2;
        return sqrt(t * (t - _a) * (t - _b) * (t - _c));
    }

    ~Triangle()
    {
        cout << "~Trangle()" << endl;
    }

private:
    double _a;
    double _b;
    double _c;
};

void func(Figure *pfig)
{
    pfig->display();
    cout << "'area:" << pfig->area() << endl;
}

int main()
{
    Rectangle rectangle(10, 20);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    func(&rectangle);
    func(&circle);
    func(&triangle);

    return 0;
}