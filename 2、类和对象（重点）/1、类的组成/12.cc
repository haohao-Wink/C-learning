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

    Point &operator=(const Point &rhs)
    {
        cout << "Point &operator=(const Point &)" << endl;

        // 赋值
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;

        return *this; // 返回对象本身，进行解引用
    }

    /*
        this指针：
            1.this指针指向对象本身
            2.this指针隐含在每一个非静态成员函数的第一个参数位置
            3.this指针不能改变指向
    */

    //!!!!注意：不要在括号内使用"//"符号进行注释，会注释掉本来的右括号
    void print(/*  " Point *const this"  */)
    {
#if 0
        this->_ix=10;//指针中的内容可以进行修改

        this=nullptr;//error，不能改变指针的指向
#endif

        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
        // printf("this:%p\n",this);//this调用的地址和对象的地址相同
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
    Point pt1(1, 2);
    cout << "pt1=";
    pt1.print();
    // printf("pt1:%p\n",&pt1);

    cout << endl;
    Point pt2(3, 4);
    cout << "pt2=";
    pt2.print();
    // printf("pt2:%p\n",&pt2);

    cout << endl;
    Point pt3(5, 6);
    cout << "pt3=";
    pt3.print();

    cout << endl;

    // pt3=pt2;

    // 赋值运算符函数
    pt3.operator=(pt3); // 等价于pt3=pt2;

    cout << "pt2=";
    pt2.print();

    cout << "pt3=";
    pt3.print();
}

int main()
{
    test();
    return 0;
}
