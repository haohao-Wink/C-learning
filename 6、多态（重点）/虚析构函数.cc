#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base
{
public:
    Base(const char *pbase)
        : _pbase(new char[strlen(pbase) + 1]())
    {
        cout << "Base(const char *)" << endl;
        strcpy(_pbase, pbase);
    }

    virtual void print() const
    {
        if (_pbase)
        {
            cout << "Base::_pbase=" << _pbase << endl;
        }
    }

    // 当把基类虚函数设置成虚函数后，派生类析构函数会自动称为虚函数
    virtual ~Base()
    {
        cout << "~Base()" << endl;
        if (_pbase)
        {
            delete[] _pbase;
            _pbase = nullptr;
        }
    }

private:
    char *_pbase;
};

class Derived
    : public Base
{
public:
    Derived(const char *pbase, const char *pderived)
        : Base(pbase), _pderived(new char[strlen(pderived) + 1]())
    {
        cout << "Derived(const char *,const char *)" << endl;
        strcpy(_pderived, pderived);
    }

    void print() const override
    {
        if (_pderived)
        {
            cout << "Derived::pderived=" << _pderived << endl;
        }
    }

    // 可以看成派生类重写基类析构函数，但是函数名称不同；
    // 对于编译器而言，就是派生类重写基类虚函数
    // 对于任何类，析构函数只有一个具有唯一性，会将析构函数称为"~destructor""
    ~Derived()
    {
        cout << "~Derived()" << endl;
        if (_pderived)
        {
            delete[] _pderived;
            _pderived = nullptr;
        }
    }

private:
    char *_pderived;
};

void test()
{
}

int main()
{
    Base *pbase = new Derived("Hello", "world");
    pbase->print();

#if 0 // 出现内存泄漏;Derived没有被析构函数销毁
    delete pbase;
#endif

#if 0
    delete dynamic_cast<Derived *>(pbase);//暴力解决
#endif

#if 0
    delete 表达式的工作步骤：
        1.执行析构函数
            pbase->~Base();//如果将基类析构函数改为派生类析构函数将解决问题
        2. 执行operator delete
#endif
    delete pbase; // 体现出多态
    pbase = nullptr;
    return 0;
}