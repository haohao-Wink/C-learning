#include <iostream>
#include <stdlib.h>
#include <pthread.h>

using std::cout;
using std::endl;

// 单例模式自动释放：atexit+pthread_once
// <pthread.h>是在Linux下的库

class Singleton
{
public:
    static Singleton *getInstance()
    {
        // 在多线程下的安全性
        pthread_once(&_once, init);
        return _pInstance;
    }

    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
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
    static pthread_once_t _once;

}; // end of class Singleton

// 饿汉模式
Singleton *Singleton::_pInstance = Singleton::getInstance(); // 防止死锁
// 初始化
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

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
