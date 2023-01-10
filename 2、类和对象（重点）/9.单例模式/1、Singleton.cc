#include <iostream>

using std::cout;
using std::endl;

// 单例模式的设计目的：一个类只能创建一个对象

class Singleton
{
public:
    //
    static Singleton *getInstance()
    {

        if (nullptr == _pInstance) // 防止创建多个对象
        {
            _pInstance = new Singleton();
        }

        return _pInstance;
    }

    static void destroy() // 防止double free
    {
        if (_pInstance) //_pInstance!=nullptr
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }

    ~Singleton() // 析构函数
    {
        cout << "~Singleton()" << endl;

#if 0 // error,循环操作，delete还是会调用析构函数
    if (_pInstance) 
    {
        delete _pInstance;
        _pInstance = nullptr;
    }
#endif
    }

private:
    static Singleton *_pInstance; // 保证每次都是同一个指针

}; // end of class Singleton

Singleton *Singleton::_pInstance = nullptr; // 初始化静态数据成员

#if 0 // error,如果能创建一个全局对象，就可以创建多个
    Singleton s1;
#endif

int main()
{

    // 在类外不能创建对象

#if 0 // 创建栈对象
    Singleton s1;// error,如果能创建一个栈对象，就可以创建多个
#endif

#if 0 // 创建堆对象
    Singleton *ps1 = new Singleton(); // error,无法访问私有变量
#endif

    Singleton *ps1 = Singleton ::getInstance();
    Singleton *ps2 = Singleton::getInstance();

    cout << "ps1=" << ps1 << endl;
    cout << "ps2=" << ps2 << endl;

    Singleton::destroy();
    Singleton::destroy();

#if 0 // 不使用指针接收
    Singleton ::getInstance();
    Singleton ::destroy(); // 构造函数时添加static即可
#endif

    return 0;
}