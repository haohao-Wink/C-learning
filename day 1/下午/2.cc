#include <iostream>

using std ::cout;
using std ::endl;

void test()
{
    int a;
    a = 20;

    cout << "hello world" << endl;
}

void test2()
{
    int value = 100;
    int *p1 = &value; // 初始化

    *p1 = 200; // 修改指针所指的内容
    p1 = NULL; // 指针的指向

    cout << *p1 << endl;

    cout << endl
         << endl;
    int value1 = 3;
    const int *p2 = &value1;
    //*p2 = 22;    // error，不能改变指针所指的内容
    p2 = &value; // 可以改变指针的指向

    int value3 = 300;
    int const &p3 = &value3;
    *p3 = 22;
    p3 = &value; // 赋值
}

int main()
{
    test2();
    return 0;
}

// const位于*右边，称为指针常量
//*p4=22;//可以改变指针所指内容
//*p4=&value//不可以改变指针指向

/*
    当const位于*左边，称为常量指针

*/

// 初始化变量前有类型
// 赋值前变量无类型

/*
函数指针和指针函数：

    函数指针：int (*pFunc)(int x);
            指针指向函数
    指针函数：int *func(int x);
            指向指针，返回类型为 int*

数组指针和指针数组

    数组指针：  int （*pArry)[]
            数组中存储指针
    指针数组:   int *pArry[]

*/

// const * const
// 既不可以改变指针所指内容也不可以改变指针指向