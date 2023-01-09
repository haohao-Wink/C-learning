#include <iostream>

using std::cout;
using std::endl;

// 单例模式的设计目的：一个类只能创建一个对象
// 用途：全局唯一的对象：字典库、词典、日志记录器

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

int main()
{
    Singleton *ps1 = Singleton ::getInstance();
    Singleton *ps2 = Singleton::getInstance();

    cout << "ps1=" << ps1 << endl;
    cout << "ps2=" << ps2 << endl;

    Singleton::destroy();
    Singleton::destroy();

    return 0;
}