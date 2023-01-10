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

    // 拷贝构造函数
    Point(const Point &rhs)
        : _ix(rhs._ix), _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    /*
        this指针：
            1.this指针指向对象本身
            2.this指针隐含在每一个非静态成员函数的第一个参数位置，由编译器自动补全
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
        printf("this:%p\n", this); // this调用的地址和对象的地址相同

        // 通过this指针，将属于此类的各个对象的数据区分开
        // 函数体内所有对此类数据成员的访问，都会转换成this->数据成员的方式
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
    printf("pt1:%p\n", &pt1);

    cout << endl;
    Point pt2(3, 4);
    cout << "pt2=";
    pt2.print();
    printf("pt2:%p\n", &pt2);
}

int main()
{
    test();
    return 0;
}
