#include <iostream>

using std ::cout;
using std ::endl;

// 即使是常量也不一定位于同一块区域
// 即使是同一变量也不一定在同一区域

// 补充：指针本身具有两个地址，一个是指针本身的地址，一个是指针指向的地址

// 全局变量，位于全局区域
int a;    // 默认初始化为0
char *p1; // 默认初始化为空

const int gMax = 10;

int main()
{

    const int x = 20;

    // 局部变量位于栈区，默认随机值
    int b; // 默认为随机值
    char *p2;

    // 静态区和全局区地址相近
    static int c = 10; // 位于静态区

    // pInt本身在栈上，指向堆区
    int *pInt = new int(10);

    const char *pstr = "hello,world"; // 文字常量区

    // 打印变量的地址
    //%p为取地址
    printf("&a=%p\n", &a);
    printf("&p1=%p\n", &p1);
    printf("p1=%p\n", p1);

    printf("&b=%p\n", &b);
    printf("&p2=%p\n", &p2);
    printf("p2=%p\n", p2);

    printf("&c=%p\n", &c);

    printf("&pInt=%p\n", &pInt);
    printf("pInt=%p\n", pInt);

    printf("&pstr=%p\n", &pstr);
    printf("pstr=%p\n", pstr);

    // 使用转义字符保证双引号
    printf("\" hello, world\"=%p\n", &"hello,world");

    // 打印变量的值
    cout << endl
         << endl;
    printf("a=%d\n", a);
    printf("b=%d\n", b);

    // 打印main函数地址的两种方式
    // 地址相同。因为函数名是函数的入口地址
    printf("&main=%p\n", &main); // 程序代码区
    printf("main=%p\n", main);

    printf("&gMax=%p\n", &gMax);
    printf("&x=%p\n", &x);

    delete pInt;
    pInt = nullptr; // 指向空指针，防止出现野指针问题
    return 0;
}