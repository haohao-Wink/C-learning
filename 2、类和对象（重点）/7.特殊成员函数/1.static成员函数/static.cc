#include <iostream>

using std::cout;
using std::endl;

/*
    静态成员函数的特点：
        静态成员函数的第一个参数的位置没有this指针
        静态成员函数不能访问非静态成员和非静态成员函数
        非静态成员函数可以访问静态数据成员和静态成员函数
        静态成员函数可以使用类名加作用域限定符进行调用
*/

// 注意：静态成员函数与const版本的成员函数都是在讨论this指针的问题

class Computer
{
public:
    Computer(const char *name, float price);

    Computer(const Computer &rhs);

    void setBrand(const char *name)
    {
        strcpy(_name, name);
    }

    void setPrice(float price)
    {
        _price = price;
    }

    void print()
    {
        cout << "void print()" << endl;

        if (_name)
        {
            cout << "name=" << _name << endl;
            cout << "price=" << _price << endl;
        }
    }

    static void printTotalPrice()
    {
#if 0 
        this->print(); // error,不能直接访问非静态成员函数
        _price = 100;              // error,不能直接访问非静态成员
        printf("this=%p\n", this); // error,静态成员函数没有地址指针
#endif

        cout << "totalPrice=" << _totalPrice << endl;
    }

    ~Computer() // 析构函数
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

private:
    char *_name;
    float _price;

    static float _totalPrice; // 总价
    /*
        static静态数据成员，只能在定义的时候进行初始化
        静态数据成员不属于对象本身，不占用对象大小空间
        位于静态区，静态数据成员被类创建的对象共享
    */
}; // end of class

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

// 深拷贝，可以解决double free问题
Computer ::Computer(const Computer &rhs)
    : _name(new char[strlen(rhs._name) + 1]()), _price(rhs._price)
{
    cout << "Computer(const Computer &)" << endl;
    strcpy(_name, rhs._name);
}

// 对于静态变量而言，不能再初始化列表中进行初始化，必须放在全局静态的位置
// 对于头文件和实现文件的形式，需要将静态变量放在实现文件中进行初始化，否则会出现多次定义的问题
float Computer::_totalPrice = 0;

void test()
{
    cout << "total price before:";

    /*
        静态成员函数既可以用类名加作用域限定符的形式调用，也可以使用类名加点的形式调用
    */

    // 如果没有对象，通过类名和作用域限定符调用函数，但是必须保证函数为静态成员函数
    Computer::printTotalPrice();

    Computer com1("lenovo", 5300);
    cout << "com1:" << endl;
    com1.print();

    cout << "buy first one total price=";
    com1.printTotalPrice();

    cout << endl;
    Computer com2("thinkpad", 6600);
    cout << "com2:" << endl;
    com2.print();

    cout << "buy second one total price=";
    com2.printTotalPrice();
} // end of test

int main()
{
    test();
    return 0;
}