#include <iostream>
#include < math.h>

using std::cout;
using std ::endl;

// 不完全类型
class Point; // 类的前向声明

/*
友元的其他特性:
    友元不受访问权限控制
    友元关系不能传递
    友元是单向的
*/

class Line
{
public:
    // 如果两个或多个函数都想访问另外一个类的私有成员，需要分别设置友元
    double distance(const Point &lhs, const Point &rhs);
    void distance(Point &pt, int ix, int iy);

private:
    int iz;

}; // end of line

class Point
{
    // 2.友元的第二种形式：友元之成员函数形式
    friend double Line::distance(const Point &lhs, const Point &rhs);

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

#if 0
void Line::distance(Point &pt, int ix, int iy)
{
    pt._ix;//error;
}
#endif

#if 0友元关系是单向的
void setLine(Line &line, int iz)
{
    line.iz = iz; // error
}
#endif

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
} // end of test

int main()
{
    test();

    return 0;
}
