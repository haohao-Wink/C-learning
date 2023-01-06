#include <iostream>

using std ::cout;
using std ::endl;

// 提前声明函数,避免在函数调用过程中，因为顺序问题而出现的无法访问命名空间的错误

// 带命名空间的函数声明
namespace wd
{
    void print();
}

namespace wh
{
    void show();
}

// 所有命名空间都可以重定义，也即无限扩展【很重要】

namespace wd
{
    // 在命名空间中可以定义变量、函数、结构体、类，将其统称为实体
    int num = 10;

    void print()
    {
        cout << "void print()" << endl;
        wh::show;
    }
} // end of namespace wd

namespace wh
{
    int number = 30;

    void show()
    {
        cout << "void wh::show" << endl;
    }

    void display()
    {
        wd::print();
    }

} // namespace wh

// 对于标准命令空间而言，尽量少去扩展，有可能会导致冲突
namespace std
{
    struct MyStrust
    {
        int a;
        int b;
    };
} // end of namespace std

int main()
{
    return 0;
}