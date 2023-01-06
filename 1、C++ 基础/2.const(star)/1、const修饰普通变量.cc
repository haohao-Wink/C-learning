#include <iostream>

using std::cout;
using std::endl;

// 宏定义
#define MAX 100

// 带参数的宏定义
#define multiply(x, y) x *y // 如果要正确计算x*y,则需要改成   `multiply(x,y)   ((x)*(y))`

/*
    宏定义发生在预处理阶段，进行直接“字符串替换”，如果宏定义发生错误，必须在运行时才能发现
    const在编译时发生，如果有错误，可以在编译时发现
*/

void test()
{
    int a;
    a = 20;

    /*
         用于const修饰的变量成为常量
         常量在定义的时候，必须初始化
     */

    // 内置类型：char / short / int / double / float / void *
    const int number = 10;
    int const number1 = 10; // const放在内置类型前后都可以

#if 0
         number = 20;//error,常量不能进行赋值
#endif

    // 结果为29，因为define只进行字符串替换
    cout << multiply(3 + 4, 5 + 6) << endl; // 3+4*5+6

    cout << "hello world" << endl;
}

int main()
{
    test();
    return 0;
}

/*
    补充：
            wimplus快捷键：ngcc快捷注释多行，u回退
*/