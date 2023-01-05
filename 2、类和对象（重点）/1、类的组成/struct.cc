#include <iostream>
using std ::cout;
using std ::endl;

struct Computer
{
#if 0
    //{}内的范围称为类的内部
public:
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
#endif

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

#if 0
    // 使用对象操作成员函数
    com.setBrand("lenove");
    com.setPrice(5300);
    com.print();
#endif
    /*
    com._price = 1000;//erroe,price是私有，不对外提供，体现了封装性
    */
}

int main()
{
    test();
    return 0;
}