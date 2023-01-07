#include <iostream>

using std::cout;
using std ::endl;

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
        没有数据返回类型，参数列表中不能有参数

        对象在销毁的时候，会自动调用析构函数
        默认情况下，编译器会自动生成析构函数
    */

private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt; // 栈对象
    cout << "pt=";
    pt.print();

#if 0
    pt.Point();//error，构造函数不能以对象加点的形式进行调用
#endif

    cout << endl;
    Point().print(); // 显示调用构造函数会创建对象

    cout << endl;
    Point pt2(3, 4); // 栈对象
    cout << "pt2=";
    pt2.print();

    // 析构函数是可以显示调用的（可以以对象进行显示调用）
    // 虽然可以显示调用析构函数，但是一般不建议
    pt2.~Point();
    pt.~Point();
}

int main()
{
    cout << "begin test..." << endl;
    test(); // test执行结束后，执行析构函数
    cout << "finish test..." << endl;
    return 0;
}