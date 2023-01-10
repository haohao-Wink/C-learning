#include <iostream>

using std::cout;
using std ::endl;

/*
    拷贝构造函数调用时机：
        1.当一个已经存在的对象初始化另一个新对象的时候，会调用拷贝构造函数
        2.当实参和形参都是对象，进行形参和实参结合的时候，会调用拷贝构造函数
        3.当函数的返回值是对象，函数调用完成返回时，会调用拷贝构造函数
*/

class Point
{
public:
    // 构造函数初始化
    Point(int ix = 0, int iy = 0)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    // 拷贝构造函数
    Point(const Point &rhs)
        : _ix(rhs._ix), _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    // 析构函数
    ~Point()
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
}; // end of point

void test()
{
    Point pt; // 栈对象
    cout << "pt=";
    pt.print();

    cout << endl;
    Point pt2(3, 4); // 栈对象
    cout << "pt2=";
    pt2.print();

    // start case1:当一个已经存在的对象初始化另一个新对象的时候，会调用拷贝构造函数
    cout << endl
         << endl;
    Point pt3 = pt2;
    cout << "pt3=";
    pt3.print(); // pt3=(3,4);
    // end of case1

} // end of test

// start case2:当实参和形参都是对象，进行形参和实参结合的时候，会调用拷贝构造函数
void func2(Point pt) // Point pt=pt1;
{
    cout << "pt=";
    pt.print();
}

void test2()
{
    Point pt1(3, 4);
    cout << "pt1=";
    pt1.print();
    cout << endl;

    func2(pt1);
}
// end of case2

// case3:当函数的返回值是对象，函数调用完成返回时,执行return语句，会调用拷贝构造函数
Point func3()
{
    Point pt3(1, 2);
    cout << "pt3=";
    pt3.print();

    return pt3; // 满足拷贝构造函数调用时机3
}

void test3()
{
    Point pt4 = func3(); // 满足拷贝构造函数调用时机1
    // func3返回的是临时对象（匿名对象）
    // 特点：对象的创建和销毁都在本行
    cout << "pt4=";
    pt4.print();
}
// end of case3

int main()
{
    test(); // case1:当一个已经存在的对象初始化另一个新对象的时候，会调用拷贝构造函数

    cout << endl
         << endl;

    test2(); // case2:当实参和形参都是对象，进行形参和实参结合的时候，会调用拷贝构造函数

    cout << endl
         << endl;

    test3(); // case3:当函数的返回值是对象，函数调用完成返回时,执行return语句，会调用拷贝构造函数

    return 0;
}
