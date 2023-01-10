#include <iostream>
#include <windows.h>
// 这个头文件为windows系统的，Linux系统为<unistd.h>

using std::cout;
using std::endl;
using std::ends;
using std::flush;

void test() // 程序正常结束刷新缓冲区
{
    // size_t 是无符号int
    for (size_t idx = 0; idx != 1024; ++idx) // 程序正常结束刷新缓冲区
    {
        cout << "a";
    }
    Sleep(5);
}

void test2() // 缓冲区满
{
    for (size_t idx = 0; idx != 1024; ++idx)
    {
        cout << "a";
    }
    cout << "b";
    Sleep(5);
}

void test3() // 手动刷新缓冲区
{
    for (size_t idx = 0; idx != 1024; ++idx)
    {
        cout << "a";
    }
    cout << "b" << endl;  // 刷新并且换行
    cout << "C" << flush; // 只刷新不换行
    cout << "d" << ends;  // 不刷新缓冲区且不换行

    Sleep(5);
}
int main()
{
    // test();// 程序正常结束刷新缓冲区
    // test2(); // 缓冲区满
    test3(); // 手动刷新缓冲区
    return 0;
}