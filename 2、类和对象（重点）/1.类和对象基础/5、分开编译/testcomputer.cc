#include "computer.h"
#include "computer.cc"

#include <iostream>

using std ::cout;
using std ::endl;

/*
    为什么要使用头文件和实现文件分开，分别编译：
        1.工程比较大，不可能就一个文件
        2.在类内部实现的成员函数是inline函数
*/

void test()
{
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
