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
            不能 ，如果去掉的话，当调用拷贝构造函数的时候，会满足形参与实参结合，会继续调用拷贝构造函数，
            然后又是一个已经存在的对象去初始化刚刚创建的对象，又会满足拷贝构造函数的调用时机，
            函数的参数一直循环入栈，
            
            ！！！会导致栈溢出！！！
            

        拷贝构造函数中参数中的const能不能去掉？
        
            不能删掉，如果传递的实参是右值，形参是没加const的左值引用；
            非const的左值引用无法绑定到右值

            const的左值引用才能绑定到右值
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

#if 0//类比
    int num=10;
    int &ref=num;
    &ref;//ok

    &num;//num为左值
    int &ref2=10;
    const int &ref;//ok

    &10;//error，是字面值常量
    &"hello,world";//ok,字符串常量，位于文字常量区
#endif

    const Point &rhs =func3();//进行形参与实参结合
    Point pt4 = func3();

    /*
        左值和右值：
            左值：可以进行取地址。字符串常量是左值
            右值：不能进行取地址。右值包括：临时变量、临时对象、匿名对象、匿名变量、字面值常量（数字）
    */

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
