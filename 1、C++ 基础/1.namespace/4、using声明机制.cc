#include <iostream>

using std ::cout;
using std ::endl;
/*
        3.using声明机制
        特点：一次只引出一个实体
*/

namespace wd
{
    // 在命名空间中可以定义变量、函数、结构体、类，将其统称为实体
    int num = 10;

    void print()
    {
        cout << "void print()" << endl;
    }
} // end of namespace wd

int main()
{
    // 输出命名空间中的变量
    cout << "num=" << wd::num << endl;
    wd::print();

    return 0;
}