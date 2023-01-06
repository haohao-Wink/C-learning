#include <iostream>

using std ::cout;
using std ::endl;

int num = 1;

namespace wd
{
    // 在命名空间中可以定义变量、函数、结构体、类，将其统称为实体
    int num = 20;

    void print(int num)
    {
        // 输出全局变量num
        cout << "num=" << ::num << endl; // 匿名命名空间

        // 输出命名空间中的num
        cout << "num=" << wd::num << endl;

        // 输出形参中的num
        cout << "num=" << num << endl;

        // C++兼容C的过程中，将C的内容全部放在了匿名命名空间中
        ::printf("hello,world\n");

        printf("hello,world\n"); // 唯一性
    }
} // end of namespace wd

int main()
{
    wd::print(30);

    return 0;
}