#include <iostream>

namespace wd
{
    int number = 20;

    void print()
    {
        std::cout << "void print()" << std::endl;
    }
} // end of namespace wd

/*
    2.作用域限定符形式
    优点：即使自定义的实体与命名空间中的实体冲突也不影响
    缺点：每个cout中都加入"std::""
    std::cout << "全局变量number=" << number <<std::endl;

*/

int cout(int x, int y)
{
    std::cout << "x=" << x << ",y=" << y << std::endl;
    return x + y;
}

int main()
{
    // 输出命名空间中的变量
    std::cout << "number=" << wd::number << std::endl;
    wd::print();

    cout(2, 3);

    return 0;
}

/*
补充：
    vim下多标签的打开和关闭：
        命名模式下："e 文件名"  打开文件
        命令模式下：":bd"   关闭当前文件
*/
