#include <iostream>
#include <limits>

using std::cout;
using std::endl;

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
        if (0 == _dreal && 0 == _dimag)
        {
            cout << 0 << endl;
        }
        else if (0 == _dimag)
        {
            cout << _dimag << "i" << endl;
        }
        else
        {
            cout << _dreal;
            if (_dimag > 0)
            {
                cout << "+" << _dimag << "i" << endl;
            }
            else if (_dimag < 0)
            {
                cout << "-" << (-1) * _dimag << "i" << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }

    // cout的两个参数：输出流对象和complex
    // std::ostream &operator<<(std::ostream &os, const Complex &rhs)//error
    // 等价于 cout<<c1<<endl;
    // std::ostream &operator<<(std::ostream &os){}// 将后半部分用this指针替代，保证参数个数一致
    // 对于输出流运算符函数而言，不能写成成员函数形式，因为违背了运算符重载原则，不能改变操作数顺序

    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);
    // 因为输出流运算符不能以成员函数形式进行重载，所以使用非成员函数；但是会访问私有成员，推荐使用友元

private:
    double _dreal;
    double _dimag;
}; // end of class

// 只有成员函数才在类内实现，所以放在类外
// 如果写成非引用，std::ostream os；拷贝构造函数已经被删掉了，无法调用
std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
    cout << "std::ostream &operator <<(std :: ostream &os,const Complex &)" << endl;
    if (0 == rhs._dreal && 0 == rhs._dimag)
    {
        os << 0 << endl;
    }
    else if (0 == rhs._dimag)
    {
        os << rhs._dimag << "i" << endl;
    }
    else
    {
        os << rhs._dreal;
        if (rhs._dimag > 0)
        {
            os << "+" << rhs._dimag << "i" << endl;
        }
        else if (rhs._dimag < 0)
        {
            os << "-" << (-1) * rhs._dimag << "i" << endl;
        }
        else
        {
            os << endl;
        }
    }
    return os;
}

void test()
{
    Complex c1(1, 2);
#if 0    
    cout << "c1=";
    c1.print();
#endif
    // 替代写法:
    cout << "c1=" << c1 << endl;
    // 完整版
    // endl为成员函数，以对象加点的形式调用
    operator<<(operator<<(cout, "c1="), c1).operator<<(endl);

#if 0 // 链式编程
    cout << "c1=" << c1 << endl
         << c1 << "hello" << 1 << endl;
#endif
}

int main()
{
    test();
    return 0;
}