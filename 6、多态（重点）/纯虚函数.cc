#include <iostream>

using std::cout;
using std::endl;

// 声明的纯虚函数类称为抽象类，抽象类不能创建对象
class Base
{
public:
    // 纯虚函数：在基类中只声明，在派生类中实现
    virtual void show() const = 0;
    virtual void print() const = 0;
};

// 如果抽象类的派生类没有将所有的纯虚函数进行实现，那么抽象类的派生类也是抽象类，抽象类不能创建对象
class Derived
    : public Base
{
public:
    // override表明重写
    virtual void show() const override
    {
        cout << "void Derived::show() const" << endl;
    }
};

class Derived2
    : public Derived
{
public:
    virtual void print() const override
    {
        cout << "void Derived2::print() const" << endl;
    }
};

void test()
{
#if 0    
    Derived derived;
    derived.show();
#endif

    Derived2 derived2;
    derived2.show();
    derived2.print();

    // 指针大小固定8B（64位系统）
    // 虽然Base是抽象类，是不完整对象，但是可以创建指针或者引用
    Base *pbase = &derived2;
    pbase->show();
    pbase->print();

    cout << endl
         << endl;
    Derived *pderived = &derived2;
    pderived->show();
    pderived->print();

    Base &ref = derived2;

    // 声明过类型之后，就可以定义类和指针
}

int main()
{
#if 0 // 声明的纯虚函数类称为抽象类，抽象类不能创建对象
    Base base;//error
#endif

    test();
    return 0;
}