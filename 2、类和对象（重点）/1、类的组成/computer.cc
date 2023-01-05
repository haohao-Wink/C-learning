#include <iostream>
using std ::cout;
using std ::endl;

// 在C++中将struct的功能做了提升，不仅可以定义变量还可以定义函数；

// 重点：默认情况下，class的访问权限是私有的，struct的访问权限是public

// 类的声明就是类中成员函数的声明
// 类的定义：成员类中成员函数的定义
class Computer
{
    //{}内的范围称为类的内部
public:
    // 默认为内联函数

    // 成员函数

    // 字符串如果不加*会报warnning
    void setBrand(const char *name)
    {
        strcpy(_name, name); // shift + k 可以进行函数跳转;
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

    /*
    com._price = 1000;//erroe,price是私有，不对外提供，体现了封装性
    */
}

int main()
{
    test();
    return 0;
}

/*
C++编码规范：

    {
    引用自定义头文件

    引用C的头文件

    引用C++头文件
    }

    引用命名空间

    定义和声明
            类名一般首字母大写
            先写public后写private
            定义函数一般为动名结构，名词首字母大写
            数据成员前加 "_"
            勤加注释，会有意想不到的好处

*/