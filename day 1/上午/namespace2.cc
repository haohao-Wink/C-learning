#include <iostream>

using std ::cout;
using std ::endl;

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
    //"::"  作用域限定符
    return 0;
}

/*
    三种形式：
        1.using编译指令
        优点：可以一次将标准命名空间中的实体全部引出
        缺点：可能会造成冲突

        2.作用域限定符形式
        优点：即使自定义的实体与命名空间中的实体冲突也不影响
        缺点：每个cout中都加入"std::""
        std::cout << "全局变量number=" << number <<std::endl;

        3.using声明机制
        特点：一次只引出一个实体
        using std::cout;
        using std::endl;
*/