#include <iostream>

using std ::cout;
using std ::endl;

// C语言的用法
void test()
{
    int iNum = 10;
    float fNum = 12.34;

    // 强制转换
    iNum = (int)fNum; // C语言
    // iNum = int(fNum);

    cout << "iNum=" << iNum << endl;
}

// C++的用法
void test2()
{
    int iNum = 10;
    float fNum = 12.34;

    // C++中普通类型的强制转换
    iNum = static_cast<int>(fNum);
    cout << "iNum=" << iNum << endl;

    // void类型的指针强制转换为（int *）的指针
    void *pret = malloc(sizeof(int));
    int *pInt = static_cast<int *>(pret);

    free(pInt);
}

void test3()
{
    const int num = 100;
    // int *pInt = &num;//error,num为常量int，不能转变为int

    int *pInt = const_cast<int *>(&num); // ok

    // 未定义的行为，由编译器决定。C++语法不承认
    *pInt = 200;
    cout << "num=" << num << endl;
    cout << "*pInt=" << *pInt << endl;

    printf("&num=%p\n", &num);
    printf("&pInt=%p\n", &pInt); // 指针本身的地址
    printf("pInt=%p\n", pInt);   // 指向的地址
}

int main()
{
    // test();
    // test2();
    test3();
    return 0;
}