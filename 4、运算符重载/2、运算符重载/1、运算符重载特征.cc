#include <iostream>
#include <limits>

using std::cout;
using std::endl;

// 复数i^2=-1
class Complex
{
public:
    Complex(double dreal = 0, double dimag = 0)
        : _dreal(dreal), _dimag(dimag)
    {
        cout << "Complex(double =0,double=0)" << endl;
    }

    void print() const
    {
        cout << _dreal << "+" << _dimag << "i" << endl;
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }

private:
    double _dreal;
    double _dimag;
}; // end of class

// 运算符重载
// 不可以重载的运算符: 成员访问运算符（.）、成员指针运算符（.*）、三目运算符（?:）、作用域限定符(::)、sizeof
Complex operator+(const Complex &lhs, const Complex &rhs) {}

// 运算符重载的规则：
#if 0 // 1. 至少有一个是类类型或者枚举类型
int operator +(int x,int y){}//error
#endif

// 2.运算符重载后，优先级和结合性不变
// 3.运算符重载后，不能改变操作数的个数与顺序，操作数不能有默认参数。

// 4.重载运算符不具备短路求值特性
#if 0
if(a && b);
if(a || b);
#endif
// 5.不要臆造不存在的运算符

void test()
{
    Complex c1(1, 2);
    cout << "c1=";
    c1.print();

    cout << endl
         << endl;
    Complex c2(3, 4);
    cout << "c2=";
    c2.print();

    cout << endl
         << endl;
    Complex c3 = c1 + c2;
    cout << "c3=" << endl;
    c3.print();
}

int main()
{
    test();
    return 0;
}