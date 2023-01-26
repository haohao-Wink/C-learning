#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(double member = 0.0)
        : _member(member)
    {
        cout << "Base(double =0.0)" << endl;
    }

    void print()
    {
        cout << "Base::_member=" << _member << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }

protected:
    double _member;
};

class Derived
    : public Base
{
public:
    Derived(double member = 0.0, double member2 = 0.0)
        : Base(member),
          _member(member2)
    //_member(mem2)
    {
        cout << "Derived(double =0.0)" << endl;
    }

    void print(int x)
    {
        cout << "Derived::x=" << x << endl;
        cout << "_member=" << _member << endl;
        cout << "Base::_member=" << Base::_member << endl;
    }

    ~Derived()
    {
        cout << "~Derived" << endl;
    }

private:
    double _member2; // 调用基类的_member
    double _member;  // 调用派生类的_member
};

void test()
{
    Derived d(11.11, 22.22);
    d.print(1);
}

int main()
{
    test();
    return 0;
}