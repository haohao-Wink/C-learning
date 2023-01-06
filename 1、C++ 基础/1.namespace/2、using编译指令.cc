#include <iostream>

using std ::cout;
using std ::endl;

// using编译指令；可以一次将标准命名空间中的实体全部引出
using namespace std;

/*
        1.using编译指令
        优点：可以一次将标准命名空间中的实体全部引出
        缺点：可能会造成冲突

*/

// 使用using编译指令，可能会导致自定义的实体与命名空间的实体冲突
#if 0
void cout(){}
#endif

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
    // 输出全局变量
    cout << "number=" << number << endl;

    // 输出命名空间中的变量
    cout << "number=" << wd::number << endl;

    // 使用"wd::number"表示命名空间变量
    //"::"  作用域限定符
    return 0;
}
