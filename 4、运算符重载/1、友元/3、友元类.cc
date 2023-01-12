#include <iostream>
#include < math.h>

using std::cout;
using std ::endl;

class Point;

class Line
{
public:
    double distance(const Point &lhs, const Point &rhs);
    void setPoint(Point &pt, int ix, int iy);
}; // end of line

class Point
{
#if 0
    friend double Line::distance(const Point &lhs, const Point &rhs);
    friend void Line::setPoint(Point &pt, int ix, int iy);
#endif

    // 友元的第三种形式：友元类
    // 如果一个类的所有成员函数都想访问另一个类的私有成员，可以设置友元类
    friend class Line;

public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")";
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
}; // end of class

double Line::distance(const Point &lhs, const Point &rhs)
{
    // sqrt(pow(lhs._ix - rhs._ix, 2)+pow(lhs._iy+rhs._iy,2));
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

void Line::setPoint(Point &pt, int ix, int iy)
{
    pt._ix = ix;
    pt._iy = iy;
}

void test()
{
    Line line;
    Point pt1(1, 2);
    Point pt2(4, 6);
    pt1.print();
    cout << "========>";
    pt2.print();
    cout << endl;

#if 0 // 方法1
    Line line;
    cout << "the distance :" << line.distance(pt1, pt2) << endl;
#endif

    // 方法2
    cout << "the distance :" << Line().distance(pt1, pt2) << endl;

    cout << endl
         << endl;
    line.setPoint(pt1, 10, 30);
    cout << "pt1=";
    pt1.print();
    cout << endl;
} // end of test

int main()
{
    test();

    return 0;
}
