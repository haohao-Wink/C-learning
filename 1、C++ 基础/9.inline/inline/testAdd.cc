// 函数测试

#include "add.h"    //自定义使用""
#include <iostream> //系统库里的使用<>

using std::cout;
using std::endl;

int main()
{
    int a = 3, c = 4;
    cout << "add(a,c)=" << add(a, c) << endl;
    return 0;
}