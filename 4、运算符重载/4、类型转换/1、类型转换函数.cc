#include <iostream>
#include <limits>

using std::cout;
using std ::endl;

// 如果有前向声明，后续只需要写  class Point
class Point;

class Complex
{
public:
    friend Point;

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

    friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);

private:
    double _dreal;
    double _dimag;
}; // end of class

std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
    cout << "std::ostream &operator<<(std::ostream &, const Complex &)" << endl;
    if (0 == rhs._dreal && 0 == rhs._dimag)
    {
        os << 0 << endl;
    }
    else if (0 == rhs._dreal)
    {
        os << rhs._dimag << "i" << endl;
    }
    else
    {
        os << rhs._dreal;
        if (rhs._dimag > 0)
        {
            os << " + " << rhs._dimag << "i" << endl;
        }
        else if (rhs._dimag < 0)
        {
            os << " - " << (-1) * rhs._dimag << "i" << endl;
        }
        else
        {
            os << endl;
        }
    }

    return os;
}

class Point
{

public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    Point(const Complex &rhs)
        : _ix(rhs._dreal), _iy(rhs._dimag)
    {
        cout << "Point(const Complex &)" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

    friend std::ostream &operator<<(std ::ostream &os, const Point &rhs);

    /*
    类型转换函数:
        1.是一个成员函数
        2.函数没有参数列表，或者说参数列表为空
        3.函数没有返回类型，即使是void也不行
        4.使用return返回目标类型的变量
    */
    operator int()
    {
        cout << "operator int()" << endl;
        return _ix + _iy;
    }

    operator double()
    {
        cout << "operator double()" << endl;
        if (0 == _iy)
        {
            return 0.0;
        }
        else
        {
            // C++版本
            // return ((double)_ix) / (_iy);

            // C版本
            return (static_cast<double>(_ix)) / (_iy);
        }
    }

    operator Complex()
    {
        cout << "operator Complex()" << endl;
        return Complex(_ix, _iy);
    }

private:
    int _ix;
    int _iy;
}; // end of class

std::ostream &operator<<(std ::ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << "," << rhs._iy << ")";

    return os;
}

void test()
{
    Point pt1(1, 2);

#if 0 // print版本
    cout << "pt1=";
    pt1.print();
#endif
    // 可以用输出流运算符替代
    cout << "pt1=" << pt1 << endl;

    // 从其他类型向自定义类型进行转换
    cout << endl
         << endl;
    Point pt2 = 10; // 隐式转换Point(10,0)

#if 0 // print版本
    cout << "pt2=";
    pt2.print();
#endif
    // 可以用输出流运算符替代
    cout << "pt2=" << pt2 << endl;

    cout << endl
         << endl;
    Complex c1(1, 2);
    Point pt3 = c1; // Point (const Complex &rhs)

#if 0
    cout << "pt3=";
    pt3.print();
#endif
    // 可以用输出流运算符替代
    cout << "pt3=" << pt3 << endl;

    // 从自定义类型向其他类型转换
    cout << endl
         << endl;
    Point pt4(4, 5);
    cout << "pt4=" << pt4 << endl;

    cout << endl
         << endl;
    int ix = pt4;
    cout << "ix=" << ix << endl;

    cout << endl
         << endl;
    double dx = pt4;
    cout << "dx=" << dx << endl;

    cout << endl
         << endl;
    Complex c2 = pt4;
    cout << "c2 = " << c2 << endl;

} // end of test

int main()
{
    test();
    return 0;
}
