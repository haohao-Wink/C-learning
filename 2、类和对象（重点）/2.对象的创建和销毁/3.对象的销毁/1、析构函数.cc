#include <iostream>

using std::cout;
using std ::endl;

// 析构函数只是对对象中的数据成员进行销毁，对象空间的销毁由对应的堆空间（程序员销毁）或栈空间（系统销毁）决定

class Point
{

public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

    /*
        析构函数：完成数据成员的清理工作
        ！！！！析构函数不能销毁对象
        没有数据返回类型，参数列表中不能有参数

        对象在销毁的时候，会自动调用析构函数
        默认情况下，编译器会自动生成析构函数
    */

private:
    int _ix;
    int _iy;
}; // end of class

void test()
{
    Point pt; // 栈对象
    cout << "pt=";
    pt.print();

    cout << endl;
    Point pt2(3, 4); // 栈对象
    cout << "pt2=";
    pt2.print();

    // 析构函数是可以显示调用的（可以以对象进行显示调用）
    // 虽然可以显示调用析构函数，但是一般不建议
    pt2.~Point();
    pt.~Point();
} // end of test

int main()
{
    cout << "begin test..." << endl;
    test(); // test执行结束后，执行析构函数（即对象在销毁的时候调用）
    cout << "finish test..." << endl;
    return 0;
}
