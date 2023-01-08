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

    _totalPrice += _price;
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

#if 0 
// 赋值运算符函数
com2 = com1; // 可能会导致内存泄漏且两个指针指向同一块空间
Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;

    // 赋值
    this->_name = rhs._name;
    this->_price = rhs._price;

    return *this; // 返回对象本身，进行解引用
}
#endif

// 如果自己复制给自己，会指向空指针
Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;

    // 赋值运算符函数四部曲

    // 1.自复制问题（考虑自己复制给自己）
    if (this != &rhs) // 防止自己复制给自己报错，指向空指针
    {
        // 2.释放左操作数
        // 目的：解决内存泄漏的问题
        //   销毁原指针
        delete[] _name;
        _name = nullptr;

        // 3.深拷贝
        //  目的：解决double free（浅拷贝）的问题

        //   开辟新空间
        _name = new char[strlen(rhs._name) + 1]();

        // 进行拷贝
        strcpy(_name, rhs._name);
        _price = rhs._price;

        this->_name = rhs._name;
        this->_price = rhs._price;
    }

    // 4.返回 *this
    return *this;
} // end of 赋值运算符函数

// 类名和作用域限定符表示
void Computer::setBrand(const char *name)
{
    strcpy(_name, name);
}

void Computer::setPrice(float price)
{
    _price = price;
}

void Computer::print(/*Computer *const this*/)
{
    cout << "void print()" << endl;

    if (_name)
    {
        cout << "name=" << _name << endl;
        cout << "price=" << _price << endl;
    }
}

// 函数之所以可以重载，是因为地址指针也即参数列表不同
// 只读不写
void Computer::print(/*Computer const *const this*/) const
{
    cout << "void print() const " << endl;

#if 0 
    this=nullptr;//error,不能改变指针指向
    this->price=1000;//error,不能改变指针内容
#endif

    if (_name)
    {
        cout << "name=" << _name << endl;
        cout << "price=" << _price << endl;
    }
}

void Computer::printTotalPrice()
{

#if 0
    this->print();//error,不能直接访问非静态成员函数
    _price=100;//error,不能直接访问非静态成员
    printf("this=%p\n",this);//error,静态成员函数没有地址指针
#endif

    cout << "totalPrice=" << _totalPrice << endl;
}

/*
    静态成员函数的特点：
        静态成员函数的第一个参数的位置没有this指针
        静态成员函数不能访问非静态成员和非静态成员函数
        非静态成员函数可以访问静态数据成员和静态成员函数
        静态成员函数可以使用类名加作用域限定符进行调用
*/

// 析构函数
Computer::~Computer()
{
    cout << "~Computer()" << endl;
    _totalPrice += _price;

    // 判断空指针
    if (_name) // if(_name!=nullptr)
    {
        delete[] _name; // 防止内存泄漏
        _name = nullptr;
    }
}

// 对于静态变量而言，不能再初始化列表中进行初始化，必须放在全局静态的位置
// 对于头文件和实现文件的形式，需要将静态变量放在实现文件中进行初始化，否则会出现多次定义的问题
float Computer::_totalPrice = 0;
