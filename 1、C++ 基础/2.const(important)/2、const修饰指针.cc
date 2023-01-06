#include <iostream>

using std ::cout;
using std ::endl;

/*
    当const位于*左边的时候，统称为常量指针（pointer to const）
        不能改变指针内容，可以改变指针指向

    当const位于*右边时，统称为指针常量（const pointer）
        不能改变指针指向，但是可以改变指针内容

    即：const修饰谁，谁就不可以改变

    const *const：
        既不可以改变指针所指内容也不可以改变指针指向

*/

/*
    函数指针和指针函数：

        函数指针：int (*pFunc)(int x);
            指针指向函数
        指针函数：int* func(int x);
            指向指针，返回类型为 int*

    数组指针和指针数组

        数组指针：  int （*pArry)[]
            数组中存储指针
        指针数组:   int* pArry[]

*/

#if 0
    int *p=&value;//初始化
    p=&value;//赋值

    注：
        初始化变量前有类型，且为第一次出现
        赋值前变量无类型，不是第一次出现
#endif

void test2()
{
    int value = 100;
    int *p1 = &value;    // 初始化
    *p1 = 200;           // 修改指针所指的内容
    cout << *p1 << endl; // 读出指针 *p1 的内容

    p1 = NULL; // 指针的指向

    cout << endl
         << endl;
    int value2 = 3;
    const int *p2 = &value2;
    //*p2 = 22;    //error，不能改变指针所指的内容
    p2 = &value; // ok,可以改变指针的指向

    cout << endl
         << endl;
    int value3 = 300;
    int const *p3 = &value3;
    //*p3 = 22;    // error，不能改变指针所指的内容
    p3 = &value; // ok,可以改变指针的指向

    cout << endl
         << endl;
    int value4 = 400;
    int *const p4 = &value4;
    *p4 = 22; // ok，不能改变指针所指的内容
    // p4 = &value; // error,可以改变指针的指向
}

int main()
{
    test2();
    return 0;
}

// const * const
// 既不可以改变指针所指内容也不可以改变指针指向