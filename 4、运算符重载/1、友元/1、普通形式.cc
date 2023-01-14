#include <iostream>
#include < math.h>

using std::cout;
using std ::endl;

//  友元,让函数访问类内的数据成员

class Point
{
    // 友元不受访问权限的控制
    friend double distance(const Point &lhs, const Point &rhs);

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

// 1.友元的第一种形式：普通形式（自由函数、全局函数）
double distance(const Point &lhs, const Point &rhs)
{
    // sqrt(pow(lhs._ix - rhs._ix, 2)+pow(lhs._iy+rhs._iy,2));
    return hypot(lhs._ix - rhs._ix, lhs._iy - rhs._iy);
}

void test()
{
    Point pt1(1, 2);
    Point pt2(4, 6);
    pt1.print();
    cout << "========>";
    pt2.print();
    cout << endl;
    cout << "the distance :" << distance(pt1, pt2) << endl;
} // end of test

int main()
{
    test();

    return 0;
}
