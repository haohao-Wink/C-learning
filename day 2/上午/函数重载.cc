#include <stdio.h>

using namespace std;

// C++支持函数重载，C语言不支持函数重载
// 定义：在同一个作用域，函数名称相同，但函数的参数列表（参数个数、类型、顺序）不一样

#if 0

//如果在同一个函数作用域，两个函数名称相同，参数列表也相同，但只靠函数的返回类型不同，不称为函数重载
int add(int x,int y){
    return x+y;
}

int add(int x,int y,int z){
    return x+y+z;
}
#endif

int main()
{
    printf("hello world");
    return 0;
}