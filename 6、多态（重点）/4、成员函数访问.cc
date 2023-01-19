#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(double base = 0.0)
        : _base(base)
    {
        cout << "Base(double=0.0)" << endl;
    }

    virtual void print() const
    {
        cout << "Base::_base=" << _base << endl;
    }

    ~Base()
    {

        cout << "~Base()" << endl;
    }

    // Base *pbase2=&derived;
    // Base * const this
    void func1()
    {
        this->print(); // 体现出多态
    }

    void func2()
    {
        Base::print();
    }

private:
    double _base;
};

class Derived
    : public Base
{
public:
    void print() const
    {
        cout << "Dervied::_derived=" << _derived << endl;
    }

    Derived(double base = 0.0, double derived = 0.0)
        : Base(base), _derived(derived)
    {
        cout << "Derived(double =0.0,double =0.0)" << endl;
    }

    ~Derived()
    {
        cout << "~Derivrd()" << endl;
    }

private:
    double _derived;
};

int main()
{
    Base base(11.11);
    Derived derived(22.22, 33.33);
    cout << endl;

    // 都是基类
    Base *pbase = &base; // 没有派生类对象
    pbase->func1();
    pbase->func2();

    cout << endl
         << endl;
    Base *pbase2 = &derived;
    pbase2->func1(); // 派生
    pbase2->func2(); // 基类

    return 0;
}