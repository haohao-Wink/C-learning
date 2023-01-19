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

    // 对象调用，没有体现出多态
    // 在编译时，已经确定调用的是哪一类的print
    base.print();
    derived.print();
    /*
        没有实现虚函数的以下特点：
            1.基类的指针指向（引用绑定）派生类的对象
            2. 使用基类的指针（引用）调用该虚函数
    */
    return 0;
}