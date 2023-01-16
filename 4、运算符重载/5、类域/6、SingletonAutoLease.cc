#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

// 单例模式自动释放：atexit+恶汉模式（解决多线程安全问题）

class Singleton
{
public:
    static Singleton *getInstance()
    {
        // 存在多线程不安全隐患
        if (nullptr == _pInstance)
        {
            _pInstance = new Singleton();
            atexit(destroy);
        }

        return _pInstance;
    }

    static void destroy() // 防止double free
    {
        cout << "void destroy()" << endl;
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

// 饱汉（懒汉）模式
//  Singleton *Singleton::_pInstance = nullptr; // 初始化静态数据成员

// 饿汉模式
Singleton *Singleton::_pInstance = getInstance(); // 防止死锁

int main()
{
    // 多线程具有随机性，可能会出现一个类创建多个对象
    Singleton *ps1 = Singleton ::getInstance();
    Singleton *ps2 = Singleton::getInstance();
    Singleton *ps3 = Singleton::getInstance();

    cout << "ps1=" << ps1 << endl;
    cout << "ps2=" << ps2 << endl;
    cout << "ps3=" << ps3 << endl;

    return 0;
}