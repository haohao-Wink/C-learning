#include <iostream>

using std::cout;
using std::endl;

// 注意：宏定义不加分号
// 宏定义在预处理阶段，只进行简单的字符串替换，一旦发生错误，只有在运行的时候才能发现
// #define multiply(x, y) x *y        // error，等到运行才能发现错误
#define multiply(x, y) ((x) * (y)) // 带参数的宏定义在使用形式上类似于普通函数

// 普通函数调用有开销
#if 0
int add(int x, int y)
{
    return x + y;
}
#endif

// 内联函数
// 当函数调用的时候，用函数体直接代替函数调用

// 内联函数是小函数，函数体内不要调用其他函数，也不要写复杂的语句（比如循环）
inline int add(int x, int y)
{
    return x + y;
}

// 内联函数的另一种写法
#if 0
inline
int add(int x, int y)
{
    return x + y;
}
#endif

int main()
{
    int a = 3, b = 4, c = 5, d = 6;
    cout << "multiply(a+b,c+d)=" << multiply(a + b, c + d) << endl;
    cout << "add(a,b)=" << add(a, b) << endl;
    return 0;
}