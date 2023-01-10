#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

// 在C++中将struct的功能做了提升，不仅可以定义变量还可以定义函数；

// 重点：默认情况下，class的访问权限是私有的，struct的访问权限是public

// 类的声明就是类中成员函数的声明
// 类的定义：成员类中成员函数的定义
class Computer // 在范围内即可，与先后顺序无关
{
    //{}内的范围称为类的内部

public:
    // 默认为内联函数

    // 成员函数
    void setBrand(const char *name) // 字符串如果不加*会报warnning
    {
        strcpy(_name, name);
    }

    void setPrice(float price)
    {
        _price = price;
    }
    void print()
    {
        cout << "name=" << _name << endl;
        cout << "price=" << _price << endl;
    }

private: // 体现封装性，不能对外提供
    // 数据成员
    char _name[20]; // 品牌
    float _price;   // 价格

}; // 分号不能去掉

void test()
{
    int a;

    // 用类创建对象
    Computer com;

    // 使用对象操作成员函数
    com.setBrand("lenove");
    com.setPrice(5300);
    com.print();

#if 0
    com._price = 1000;//error,price是私有的
#endif
}

int main()
{
    test();
    return 0;
}
