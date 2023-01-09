#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
using std ::cout;
using std ::endl;

// 类的声明
class Computer
{
public:
    Computer(const char *name, float price);

    Computer(const Computer &rhs);

    Computer &operator=(const Computer &rhs);

    void setBrand(const char *name);
    void setPrice(float price);
    void print();

    // 函数重载
    void print() const; // 建议先写const版本的成员函数

    static void printTotalPrice();

    ~Computer();

private:
    // 内存对齐
    char *_name;
    float _price;

    static float _totalPrice; // 总价
    /*
        static静态数据成员，只能在定义的时候进行初始化
        静态数据成员不属于对象本身，不占用对象大小空间
        位于静态区，静态数据成员被类创建的对象共享
    */
};

#if 0 // 如果放在头文件，会导致多次定义
float Computer::_totalPrice = 0;
#endif

#endif

// 静态成员函数与const版本的成员函数都是在讨论this指针的问题