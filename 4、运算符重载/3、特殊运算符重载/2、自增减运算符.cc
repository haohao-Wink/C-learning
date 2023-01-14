#include <iostream>
#include <limits>

using std::cout;
using std::endl;

// 复数i^2=-1
class Complex
{
    // 3.以友元的形式重载
    friend Complex operator+(const Complex &lhs, const Complex &rhs);

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

    // c3+=c1
    // 对象本身会发生变化
    // 对于复合赋值运算符函数，以成员函数的形式进行重载
    Complex &operator+=(const Complex &rhs)
    {
        cout << "Complex &operator +=(const Complex &rhs)" << endl;
        _dreal += rhs._dreal;
        _dimag += rhs._dimag;
        return *this;
    }

    // 前置加加
    Complex &operator++()
    {
        cout << "Complex &operator++()" << endl;
        ++_dreal;
        ++_dimag;
        return *this;
    }

    // 后置加加
    // int只有标识作用，不代表传参问题
    Complex operator++(int)
    {
        cout << "Complex operator++(int)" << endl;
        Complex tmp(*this); // 局部对象tmp
        _dreal++;
        _dimag++;
        return tmp;
    }

    /*
        前置加加和后置加加的区别：
            1.前置加加返回对象的 引用，是左值，可以取地址；后置加加返回的是局部对象，是右值，不能取地址
            2. 前置加加的效率高于后置加加

    */

private:
    double _dreal;
    double _dimag;
}; // end of class

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    cout << "friend complex operator +(const complex &lhs,const complex &rhs)" << endl;
    ;
    return Complex(lhs._dreal + rhs._dreal, lhs._dimag + rhs._dimag);
}

void test()
{

#if 0 // 示例
    int a = 3;
    int b = 4;
    a += b;//a=7;

    cout << "(++a)=" << (++a) << ",a=" << a << endl;//8,8
    cout << "(a++)=" << (a++) << ",a=" << a << endl;//8,9
#endif

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
    cout << "c3=";
    c3.print();

    cout << endl
         << endl;
    (++c3);
    cout << "(++c3)=";
    c3.print();
    cout << "c3=";
    c3.print();

    cout << endl
         << endl;
    (c3++);
    cout << "(c3++)=";
    c3.print();
    cout << "c3=";
    c3.print();
}

int main()
{
    test();
    return 0;
}