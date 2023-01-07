#include "Computer.h"
#include <string.h>

// 对象在销毁的时候会自动调用析构函数

// 构造函数
Computer::Computer(const char *name, float price)
    : _name(new char[strlen(name) + 1]()) // 将指针指向堆空间
      ,
      _price(price)
{
    cout << "Computer(const char *,float)" << endl;

#if 0 // 和初始化同义
    _name=new char[strlen(name)+1]();//+1是保证'\0'
#endif

    strcpy(_name, name);
}

#if 0 // 浅拷贝：两个指针指向同一区域
//编译器自动生成，不能满足需求
Computer ::Computer(const Computer &rhs)
    : _name(rhs._name), _price(rhs._price) 
{
    cout << "Computer(const Computer &)" << endl;
}
#endif

// 深拷贝，可以解决double free问题
Computer ::Computer(const Computer &rhs)
    : _name(new char[strlen(rhs._name) + 1]()), _price(rhs._price)
{
    cout << "Computer(const Computer &)" << endl;
    strcpy(_name, rhs._name);
}

// 类名和作用域限定符表示
void Computer::setBrand(const char *name)
{
    strcpy(_name, name);
}

void Computer::setPrice(float price)
{
    _price = price;
}
void Computer::print()
{
    cout << "name=" << _name << endl;
    cout << "price=" << _price << endl;
}

// 析构函数
Computer::~Computer()
{
    cout << "~Computer()" << endl;

    // 判断空指针
    if (_name) // if(_name!=nullptr)
    {
        delete[] _name; // 防止内存泄漏
        _name = nullptr;
    }
}
