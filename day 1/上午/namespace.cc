#include <iostream>

using std ::cout;
using std ::endl;

int number = 20;

// 命名空间之后，不需要打分号
namespace wd
{
    // 在命名空间中，可以定义变量函数、结构体、类，统称为实体
    int number = 10;
    void print()
    {
        cout << "void print()" << endl;
    }
} // end of namespace wd

int main()
{
    cout << "全局变量number=" << number << endl;
    cout << "命名空间number=" << number << endl;

    // 使用"wd::number"表示命名空间变量
    //""  作用域限定符
    return 0;
}