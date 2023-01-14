#include <iostream>
#include <limits>

using std::cin;
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

    // 删掉const,因为const修饰的变量为常量，不可以进行输入
    // 输入流也是以友元函数的形态进行重载
    friend std::istream &operator>>(std ::istream &is, Complex &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);

private:
    double _dreal;
    double _dimag;
}; // end of class

// 防止出现不规则输入
void readDouble(std ::istream &is, double &rhs)
{
    while (is >> rhs, !is.eof())
    {
        if (is.bad())
        {
            std ::cerr << "istream is bad";
            return;
        }
        else if (is.fail())
        {
            is.clear();                                                   // 重置流的状态
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空缓冲区
            cout << "please cin double num" << endl;
        }
        else
        {
            cout << "rhs=" << rhs << endl;
            break; // 终止循环
        }
    }
}

std::istream &operator>>(std ::istream &is, Complex &rhs)
{
    cout << "std :: istream &operator >>(std :: istream &is,complex &)" << endl;
    // is >> rhs._dreal >> rhs._dimag;
    readDouble(is, rhs._dreal);
    readDouble(is, rhs._dimag);
    return is;
}

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
    Complex c1;
    cin >> c1;
    cout << "c1=" << c1 << endl;
}

int main()
{
    test();
    return 0;
}