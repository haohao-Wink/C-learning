#include <iostream>

using std::cout;
using std::endl;

class Base
{
    friend void setBase(Base &base, double dx);

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

void func(Base *pbase)
{
    pbase->print(); // 指针访问虚函数
}

int main()
{
    Base base(11.11);
    Derived derived(22.22, 33.33);
    cout << endl;

    func(&base);    // Base *pbase =&base;
    func(&derived); // Base *pbase=&derived;

    return 0;
}