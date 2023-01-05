#include "computer.h"
#include <iostream>
using std ::cout;
using std ::endl;

void test()
{
    int a;
    // 用类创建对象
    Computer com;

    // 使用对象操作成员函数
    com.setBrand("lenove");
    com.setPrice(5300);
    com.print();
}

int main()
{
    test();
    return 0;
}
