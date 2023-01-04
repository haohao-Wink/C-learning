#include <iostream>

using namespace std;
using std ::cout;
using std ::endl;

// 宏定义
#define MAX 100

// 带参数的宏定义
#define multiply(x, y) x *y

void test()
{
    int a;
    a = 20;
    // ngcc快捷注释多行，u回退
    /*
    用于const修饰的变量成为常量
    常量在定义的时候，必须初始化
    */
    const int number = 10;
    // 常量不能进行赋值

    /*
        内置类型：char/short/int/double/float/void *
    */
    cout << "hello world" << endl;
}

int main()
{
    test();
    return 0;
}

/*
    宏定义发生在预处理阶段，进行直接！！字符串替换！！
        如果宏定义发生错误，必须在运行时才能发现
    const在编译时发生，如果有错误，可以在编译时发现
*/
