#include <iostream>

using std::cout;
using std::endl;

// 单例模式自动释放：内部类+静态数据成员

class Singleton
{
public:
    static Singleton *getInstance()
    {

        if (nullptr == _pInstance)
        {
            _pInstance = new Singleton();
        }

        return _pInstance;
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

    class AutoRealse
    {
    public:
        AutoRealse()
        {
            cout << "AutoRealse()" << endl;
        }

        ~AutoRealse()
        {
            cout << "~AutoRealse()" << endl;
            if (Singleton::_pInstance) //_pInstance!=nullptr
            {
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };

private:
    static Singleton *_pInstance; // 保证每次都是同一个指针

    // AutoRease _ar;                // 只有执行析构函数时才会销毁_ar，进而形成死锁

    static AutoRealse _ar;

}; // end of class Singleton

Singleton *Singleton::_pInstance = nullptr; // 初始化静态数据成员

Singleton::AutoRealse Singleton::_ar; // 无参初始化

int main()
{
    Singleton *ps1 = Singleton ::getInstance();
    Singleton *ps2 = Singleton::getInstance();

    cout << "ps1=" << ps1 << endl;
    cout << "ps2=" << ps2 << endl;

#if 0
    AutoRease ar; // error
#endif

#if 0 // 删去destroy()不会导致内存泄漏，进程正常结束后，会自动回收
    Singleton::destroy();
    Singleton::destroy();
#endif

    /*
        自动检测内存泄漏的工具：vagrind
    */

    return 0;
}