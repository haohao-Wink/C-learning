#include <iostream>

using std ::cout;
using std ::endl;

// 带命名空间的函数声明
// 命名空间可以进行扩展（所有命名空间都可以）
namespace wd
{
    void print();
}

// 对于标准命令空间而言，尽量少去扩展，有可能会导致冲突
namespace std
{
    struct MyStrust
    {
        int a;
        int b;
    };
} // end of namespace std

// using编译指令
// 可以一次将标准命名空间中的实体全部引出

using namespace std;

// 有可能自定义的实体与命名空间的实体冲突
#if 0
void cout()
{

}
#endif

int number = 20;

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

namespace wd
{

    int number = 10;
    void print()
    {
        cout << "void print()" << endl;
        wh::show();
    }
}

void test()
{
}

int main()
{
    cout << "全局变量number=" << number << endl;
    cout << "命名空间number=" << number << endl;

    return 0;
}

/*
    vim下多标签的打开和关闭：
        命名模式下："e 文件名"  打开文件
        命令模式下：":bd"   关闭当前文件
*/
