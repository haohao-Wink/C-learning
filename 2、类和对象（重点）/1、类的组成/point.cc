#include <iostream>
using std::cout;
using std ::endl;

// 由构造函数进行初始化

class Point
{
public:
    // 默认情况下，编译器会自动生成一个默认构造函数

    // 如果自定义了构造函数，编译器就不会为我们生成默认构造函数
    // 如果想创建无参对象，可以 显示写出无参构造

    // Point(){}
    // 是一个无参的构造函数

    // 构造函数的作用：为了完成数据成员初始化

    // 构造函数没有返回类型
#if 0
    Point()
    // ！！注意初始化列表（初始化表达式）位置
    //        : _ix(0), _iy(0)//初始化
    {
        // _ix = 0;
        //_iy = 0;
        cout << "Point()" << endl;
    }

#endif

    // 构造函数可以进行重载

    Point(int ix, int iy)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point()" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt; // 用类创建对象，会自动调用构造函数
    cout << "pt=";
    pt.print();

    cout << endl;
    Point pt2(3, 4);
    cout << "pt2=";
    pt2.print();
}

int main()
{
    test();
    return 0;
}

// 拷贝调用函数的调用时机：当用一个已经存在的对象去初始化另一个新对象的时候

// 当实参和形参都是对象，进行实参和形参结合的时候

void func2(Point pt)
{
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