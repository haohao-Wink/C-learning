#include <iostream>

using std::cout;
using std::endl;

class Base
{
    // 将构造函数用protected修饰的类，也称为抽象类；
    // 抽象类也不能创建对象，但构造函数可以被派生类访问
protected:
    Base()
    {
        cout << "Base()" << endl;
    }
};

class Derived
    : public Base
{
public:
    Derived()
        : Base()
    {
        cout << "Derived()" << endl;
    }
};

void test()
{

#if 0 // 当Base构造函数私有时
        Base base;//error
        Derived derived;//error
#endif

    Derived derived;
    // Bass bass;//error
}

int main()
{
    return 0;
}