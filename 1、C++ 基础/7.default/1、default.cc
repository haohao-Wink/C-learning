#include <iostream>

using std::cout;
using std::endl;

// 给函数参数设置默认值
// 默认参数必须从右向左连续赋初值
int add(int x = 100, int y = 10, int z = 0) // 相当于定义了多个add函数
{
    return x + y + z;
}

// error,对重载函数调用不明确
// 具有二义性
#if 0
int add(int x, int y)
{
    return x + y;
}
#endif

int main()
{
    int a = 3, b = 4, c = 5;
    cout << "add(a,b,c)=" << add(a, b, c) << endl;
    cout << "add(a,b)=" << add(a, b) << endl;
    cout << "add(a)=" << add(a) << endl;
    cout << "add()=" << add() << endl;
    return 0;
}