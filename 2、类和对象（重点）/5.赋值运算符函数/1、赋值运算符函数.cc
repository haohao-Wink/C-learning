#include <iostream>

using std::cout;
using std ::endl;

// 浅拷贝方式拷贝字符串

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

#if 0 // 赋值运算符函数
    默认情况下，编译器会默认生成赋值运算符函数

    Q1.赋值运算符函数参数中的引用能不能去掉
    A1.在形参与实参结合的时候，多执行一次拷贝构造函数

    Q2.赋值运算符函数参数中的引用能不能去掉
    A2.非const左值引用不能绑定到右值.当用右值进行赋值时会出现问题

    Q3.赋值运算符函数返回类型中的引用能不能去掉
    A3.函数的返回类型为类类型,回满足拷贝构造函数调用的时机3,会直接拷贝构造函数

    Q4.赋值运算符函数的返回类型可以不是对象吗
    A4.连等的情况下,返回类型不一定匹配

#endif

    // 赋值运算符函数
    Point &operator=(const Point &rhs)
    {
        cout << "Point &operator=(const Point &)" << endl;

        // 赋值
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;

        return *this; // 返回对象本身，进行解引用
    }

    void print()
    {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt(3, 4);
    cout << "pt=";
    pt.print();

    cout << endl;
    Point pt1(5, 6);
    cout << "pt1=";
    pt1.print();

    cout << endl;
    // 赋值运算符函数
    pt1.operator=(pt); // 等价于pt1=pt;

    cout << "pt=";
    pt.print();

    cout << "pt1=";
    pt1.print();
}

int main()
{
    test();
    return 0;
}
