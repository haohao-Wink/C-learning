#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(double mem = 0.0)
        : _member(mem)
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

private:
    double _member;
};

class Derived
    : public Base
{
public:
    Derived(double mem = 0.0)
        : Base(mem)
    {
        cout << "Derived(double =0.0)" << endl;
    }

    void print(int x)
    {
        cout << "Derived::x=" << x << endl;
    }

    ~Derived()
    {
        cout << "~Derived" << endl;
    }
};

void test()
{
    Derived d(11.11);

    // d.print();
    // error,0参数print已经被屏蔽掉了

    // 可以使用作用域限定符形式进行调用
    d.Base::print();

    d.print(11.11); // 隐藏

    // 注：无论是不是虚函数，都不会影响结论
}

int main()
{
    test();
    return 0;
}