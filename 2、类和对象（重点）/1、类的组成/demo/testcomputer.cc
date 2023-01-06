#include "computer.h"

using std ::cout;
using std ::endl;

void test()
{
    // 用类创建对象
    Computer com;

    // 使用对象操作成员函数
    com.setBrand("lenove");
    com.setPrice(5300);
    com.print();
}

int main()
{
    // test();
    cout << "hello world";
    return 0;
}
