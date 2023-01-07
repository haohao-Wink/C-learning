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

    /*
        拷贝构造函数中的引用符号能不能去掉？
            

        拷贝构造函数中参数中的const能不能去掉？
    */

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
};

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

int func00()
{
    int num = 10;
    return num;
}

Point func3()
{
    Point pt3(1, 2);
    cout << "pt3=";
    pt3.print();

    return pt3;//满足拷贝构造函数调用时机3
}

void test3()
{
    Point pt4 = func3();

    cout << "pt4=";
    pt4.print();
}



int main()
{

#if 0
    cout << "begin test..." << endl;
    test(); // test执行结束后，执行析构函数（即对象在销毁的时候调用）
    cout << "finish test..." << endl;
#endif

#if 0
    test2();
#endif

    test3();

    return 0;
}
