#include <iostream>

using std::cout;
using std::endl;

class Base
{
public:
    Base(long base = 0)
        : _base(base)
    {
        cout << "Base(long =0)" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }

    virtual void f()
    {
        cout << "void Base::f()" << endl;
    }

    virtual void g()
    {
        cout << "void Base::g()" << endl;
    }

    virtual void h()
    {
        cout << "void Base::h()" << endl;
    }

private:
    long _base;
};

class Derived
    : public Base
{
public:
    Derived(long base = 0, long derived = 0)
        : Base(base), _derived(derived)
    {
        cout << "Derived(long =0,long =0)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

    virtual void f()
    {
        cout << "void Derived::f()" << endl;
    }

    virtual void g()
    {
        cout << "void Derived::g()" << endl;
    }

    virtual void h()
    {
        cout << "void Derived::h()" << endl;
    }

private:
    long _derived;
};

void test()
{
    Derived derived(10, 20);
    printf("derived'address=%p\n", &derived);
    printf("vtable'address=%p\n", (long *)*(long *)&derived);
    printf("di yi ge xu han shu ru kou'address=%p\n", (long *)*(long *)*(long *)&derived);

    // 等价于
    // printf("di yi ge xu han shu ru kou'address=%p\n", **&derived);//error

    typedef void (*pFunc)(void); // 函数指针
    // typedef void (*) (void ) pFunc;//语法不支持
    pFunc pf = nullptr;
    pf = (long *)&derived
    // 虚表存在性验证 30.05
}

int main()
{
    test();
    return 0;
}