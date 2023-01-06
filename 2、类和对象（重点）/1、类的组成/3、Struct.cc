#include <iostream>
using std ::cout;
using std ::endl;

// 在C++中将struct的功能做了提升，不仅可以定义变量还可以定义函数；

// 重点：默认情况下，class的访问权限是私有的，struct的访问权限是public

struct Computer
{
public:
    // 成员函数
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

private:
    //  数据成员
    char _name[20]; // 品牌
    float _price;   // 价格

}; // 分号不能去掉

void test()
{
    int a;
    Computer com;

    com.setBrand("lenove");
    com.setPrice(5300);
    com.print();

    // com._price = 1000;
}

int main()
{
    test();
    return 0;
}