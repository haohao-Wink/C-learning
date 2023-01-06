// C语言头文件
#include <stdio.h>

// C++头文件使用模板进行编写
#include <iostream> //IO流

// 命名空间
using namespace std;

// 函数声明（可以有多个）
void test() {}

// 函数定义（只有一个，否则就是重定义（redefinition））

int main(int argc, char **argv)
{
    printf("hello world\n"); // C语言形式

    /*
        cout  输出流对象，类似于printf
        <<    输出流运算符
        hello world 字符串常量
        endl    换行符

     */
    cout << "hello world" << endl; // C++形式

#if 0
    //运算符重载(和上面C++形式相互等价)
    operator<<(cout, "hello world");
    cout.operator<<(endl);//endl 函数

    //合在一起的写法
    operator<<(cout, "hello world").operator<<(endl);
#endif

    int num = 0;
    // cin 输入流对象 ，类似于scanf
    //>> 输入流运算符
    cin >> num;
    cout << "num=" << num << endl;

    return 0;
}

/*
函数声明与函数定义的区别：
    1.有没有函数体即 "{}"
    2.函数声明可以有多次
*/

#if 0
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
#endif

/*
    C语言进行开发，print,print冲突，修改函数名称
    C++解决命名冲突，使用命名空间
*/

/*

快捷注释暂时不用的代码
#if 0
#endif

*/

#if 0
./a.out//表示在当前目录下执行a.out文件
#endif