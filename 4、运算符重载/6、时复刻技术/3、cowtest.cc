#include <iostream>

using std::cout;
using std::endl;

// 引用计数存在内存中的什么位置：
//  1. 栈 2. 全局静态

class String
{
public:
    String() {}

    String(const String &rhs)
        : _pstr(rhs._pstr)
    {
    }

private:
    char *_pstr;
    int _refCount;
};

void test()
{
    String s1;
    String s2 = s1;
}

int main() {}