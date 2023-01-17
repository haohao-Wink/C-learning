#include <iostream>

using std::cout;
using std::endl;

// 引用计数存在内存中的什么位置：
//  1. 栈 2. 全局静态 3.文字常量区\程序代码区 4.堆（程序员可用最灵活的位置）
// 存放在字符串前四个字节

/*
class String
{
public:
    String() {}

    String(const String &rhs)
        : _pstr(rhs._pstr), _refCount(rhs._refCount)
    {
#if 0 // 栈不可行
        ++rhs._refCount;//error
#endif
    }

private:
    char *_pstr;

    // int _refCount;
    static int _refCount;
};

void test()
{
    String s1;
    String s2 = s1;
    // String s3("hello");error
}

int main() {}
*/