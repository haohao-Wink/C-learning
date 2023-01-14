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

    // 隐含this指针,保证参数数量一致，删去第一个参数
    Complex operator+(const Complex &rhs) // 2.以成员函数形式进行重载
    {
        cout << "complex Complex::operator +(const complex &)" << endl;
        ;
        return Complex(_dreal + rhs._dreal, _dimag + rhs._dimag);
    }

private:
    double _dreal;
    double _dimag;
}; // end of class

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
    cout << "c3=";
    c3.print();
}

int main()
{
    test();
    return 0;
}