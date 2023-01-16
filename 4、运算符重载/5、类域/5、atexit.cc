#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

void function()
{
    cout << "void function()" << endl;
}

int main()
{
    cout << "begin main ..." << endl;

    /*
        atexit:
            1.注册给定函数类型（参数类型是void，返回类型是void）
            2.注册的函数在进程正常结束的时候被调用
            3.函数注册几次就执行几次
    */
    atexit(function); // 在main函数之后执行
    cout << "end main ..." << endl;
    return 0;
}