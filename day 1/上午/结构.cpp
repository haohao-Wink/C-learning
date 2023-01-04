// C语言头文件
#include <stdio.h>

// C++头文件使用模板进行编写
#include <iostream>

// 命名空间
using namespace std;

// 函数声明（可以有多个）
void test() {}

/*

快捷注释暂时不用的代码
#if 0
#endif

*/

// 函数定义（只有一个，否则就是重定义（redefinition））

int main(int argc, char **argv)
{
    cout << "hello world" << endl;

#if 0

    重载
    operator<<(cout, "hello world");
    cout.operator<<(endl);

    operator<<(cout, "hello world").operator<<(endl);

#endif
    /*
        cout  输出流对象
        <<    输出流运算符
        hello world 字符串常量
        endl    换行符
    */

    // cin、scanf    输入流对象
    //>>    输入流运算符

    return 0;
}

// 结构体
struct A
{
    int a;
    int x;
    /* data */
};

void test3()
{
    struct A aa;
    aa.a = 10;
}

/*
    C语言进行开发，print,print冲突，修改函数名称
    C++解决命名冲突，使用命名空间
*/
