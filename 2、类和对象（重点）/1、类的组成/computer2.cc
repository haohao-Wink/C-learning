#include <iostream>
using std ::cout;
using std ::endl;

class Computer
{

public:
    void setBrand(const char *name);
    void setPrice(float price);
    void print();

private:
    char _name[20];
    float _price;
};

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
