#include <iostream>

using std::cout;
using std ::endl;

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

    // 拷贝构造函数（复制构造函数）
    // 默认情况下，会自动生成拷贝构造函数
    Point(const Point &rhs)
        : _ix(rhs._ix), _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
}; // end of class

void test()
{
    Point pt; // 栈对象
    cout << "pt=";
    pt.print();

    // 栈是先入后出的，所以pt2先销毁
    cout << endl;
    Point pt2(3, 4); // 栈对象
    cout << "pt2=";
    pt2.print();

    cout << endl
         << endl;
    // 当一个已经存在的对象初始化另一个新对象的时候，会调用拷贝构造函数
    Point pt3 = pt2;
    cout << "pt3=";
    pt3.print(); // pt3=(3,4);
}

int main()
{
    cout << "begin test..." << endl;
    test(); // test执行结束后，执行析构函数（即对象在销毁的时候调用）
    cout << "finish test..." << endl;

    return 0;
}
