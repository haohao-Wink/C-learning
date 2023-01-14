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
    Complex c2(1, 0);
    cout << "c2=";
    c2.print();

    cout << endl
         << endl;
    Complex c3(1, -2);
    cout << "c3=";
    c3.print();

    cout << endl
         << endl;
    Complex c4(0, 2);
    cout << "c4=";
    c4.print();

    cout << endl
         << endl;
    Complex c5(0, 0);
    cout << "c5=";
    c5.print();

    cout << endl
         << endl;
    Complex c6(0, -2);
    cout << "c6=";
    c6.print();

    cout << endl
         << endl;
    Complex c7(-1, 2);
    cout << "c7=";
    c7.print();

    cout << endl
         << endl;
    Complex c8(-1, 0);
    cout << "c8=";
    c8.print();

    cout << endl
         << endl;
    Complex c9(-1, -2);
    cout << "c9=";
    c9.print();
}

int main()
{
    test();
    return 0;
}