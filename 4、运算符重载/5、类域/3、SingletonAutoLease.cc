#include <iostream>

using std::cout;
using std::endl;

// 单例模式自动释放：友元类

class Singleton
{
    friend class AutoRease;

public:
    static Singleton *getInstance()
    {

        if (nullptr == _pInstance)
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
    }

private:
    static Singleton *_pInstance; // 保证每次都是同一个指针

}; // end of class Singleton

Singleton *Singleton::_pInstance = nullptr; // 初始化静态数据成员

class AutoRease
{
public:
    AutoRease()
    {
        cout << "AutoRease()" << endl;
    }

    ~AutoRease()
    {
        cout << "~AutoRease()" << endl;
        if (Singleton::_pInstance) //_pInstance!=nullptr
        {
            delete Singleton::_pInstance;
            Singleton::_pInstance = nullptr;
        }
    }
};

int main()
{
    Singleton *ps1 = Singleton ::getInstance();
    Singleton *ps2 = Singleton::getInstance();

    cout << "ps1=" << ps1 << endl;
    cout << "ps2=" << ps2 << endl;

    AutoRease ar; // 栈对象，生命周期结束后会自动使用析构函数

#if 0 // 删去destroy()不会导致内存泄漏，进程正常结束后，会自动回收
    Singleton::destroy();
    Singleton::destroy();
#endif

    /*
        自动检测内存泄漏的工具：vagrind
    */

    return 0;
}