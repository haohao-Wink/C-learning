#include <iostream>
#include <stdlib.h> //使用malloc
#include <string.h> //使用memset

using std::cout;
using std::endl;

// 定义：在同一个作用域，函数名称相同，但函数的参数列表（参数个数、类型、顺序）不一样
// C++支持函数重载，C语言不支持函数重载

// 函数重载的原理：当用同名函数的时候，会根据参数类型、参数个数、参数顺序对函数名字进行改编

int add(int x, int y)
{
    return x + y;
}

// 如果在同一个函数作用域，两个函数名称相同，参数列表也相同，但只靠函数的返回类型不同，不称为函数重载
#if 0
double add(int x, int y)
{
    return x + y;
}
#endif

int add(int x, int y, int z)
{
    return x + y + z;
}

void test()
{
    // C++在编译的时候，将C的代码按照C进行编译
    int *pInt = static_cast<int *>(malloc(sizeof(int)));
    memset(pInt, 0, sizeof(int));

    free(pInt);
    // pInt = NULL; // 否则会产生野指针
    pInt = nullptr; // C++11版本
}

int main()
{
    test();
    return 0;
}