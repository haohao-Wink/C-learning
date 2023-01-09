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

void test3()
{
    Computer com1("lenovo", 5300);
    cout << "com1:" << endl;
    com1.print();

    cout << endl;
    Computer com2("thinkpad", 6600);
    cout << "com2:" << endl;
    com2.print();

    cout << endl;

    com2 = com1;

    cout << "com1:" << endl;
    com1.print();

    cout << "com2:" << endl;
    com2.print();
}

void test4()
{
    cout << "sizeof(computer)=" << sizeof(Computer) << endl;

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
} // end of test4

void test5()
{
    // 默认情况下，非const对象调用非const版本的成员函数，const对象调用const版本的成员函数
    // 非const对象也可以调用const版本的成员函数,const对象不能调用非const版本的成员函数

    Computer com1("lenovo", 5300);
    cout << "com1:" << endl;
    com1.print();

    cout << endl;
    // const int num=10;
    const Computer com2("thinkpad", 6600);
    cout << "com2:" << endl;
    com2.print();
}

int main()
{
    // cout << "enter main..." << endl;

#if 0   
    test();
#endif

    // test2();

    // test3();
    // test4();
    test5();
    return 0;
}
