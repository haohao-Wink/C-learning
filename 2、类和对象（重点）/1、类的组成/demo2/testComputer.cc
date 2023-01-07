#include "Computer.h"
#include "Computer.cc"
#include <iostream>

using std ::cout;
using std ::endl;

#if 0 // 最后销毁
Computer gCom("xiaomi", 7000); // 全局对象
#endif

void test()
{
#if 0
    gCom.print();
    cout << endl;
#endif

    Computer com("lenovo", 5300); // 类创建类对象，栈对象
    // 第二个销毁

#if 0 // 显示调用析构函数
    com.~Computer(); // 可能会清理掉数据成员
#endif

    com.print();

    cout << endl;
    // pc是连接堆空间的指针，pc位于栈，指向堆
    Computer *pc = new Computer("huawei", 10000); // 堆对象
    pc->print();

    // 堆空间需要程序员手动释放
    delete pc;
    pc = nullptr; // 第一个执行析构函数
} // end of test

void test2()
{
    Computer com("lenovo", 5300); // 类创建类对象，栈对象
    com.print();

    cout << endl;

    Computer com2 = com;
    com2.print(); // 先执行析构函数

    cout << endl;
    com2.setBrand("MAC"); // 使用深拷贝之后，改变com2的值不会改变com

    com.print();
    com2.print();
}

int main()
{
    cout << "enter main..." << endl;

#if 0   
    test();
#endif

    test2();
    return 0;
}
