#include <iostream>

using std::cout;
using std::endl;

class Base; // 前向声明

// 体现多态一定要有虚函数，但虚函数不一定都体现多态
class Line
{
public:
    virtual void setBase(Base &base, double dx);
};

class Base
{
    friend void setBase(Base &base, double dx);

public:
    Base(double base = 0.0)
        : _base(base)
    {
        cout << "Base(double=0.0)" << endl;
    }

    // 如果不加virtual，只会调用base函数
    // 多一个虚函数指针(vfptr)，指向虚函数表，虚函数表存储所有该类虚函数入口地址
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
    // 返回类型要相同，否则不满足重载条件
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

#if 0 // 如果有多个虚函数，仍然只有一个虚函数指针，指向一个表
    virtual void show(){}
#endif

private:
    double _derived;
};

void func(Base *pbase)
{
    pbase->print(); // 对于同一种指令
}

int main()
{
    // 如果非多态，为8 16；多态 16 24（多了虚函数指针）
    cout << "sizeof(Base)=" << sizeof(Base) << endl;
    cout << "sizeof(Derived)=" << sizeof(Derived) << endl;
    cout << endl
         << endl;

    Base base(11.11);
    Derived derived(22.22, 33.33);
    cout << endl;

    // 基类对象，基类的print行为
    func(&base); // Base *pbase =&base;

    // 派生类对象，派生类的print行为
    func(&derived); // Base *pbase=&derived;

    cout << "sizeof(Base)=" << sizeof(Base) << endl;
    cout << "sizeof(Derived)=" << sizeof(Derived) << endl;
    return 0;
}