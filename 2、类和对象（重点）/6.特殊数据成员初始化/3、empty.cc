#include <iostream>

using std ::cout;
using std ::endl;

class Empty
{
    /*
    空类默认生成四个构造函数：
        1.普通构造函数（无参构造函数）
        2.拷贝构造函数
        3.赋值运算符函数
        4.析构函数
    */
};

int main()
{
    cout << "sizeof(Empty)=" << sizeof(Empty) << endl;

    Empty e1; // 空类可以创造对象
    Empty e2;

    // 地址不同，证明空类生成的对象不同
    // 通过编译器分配的一个字节来区别不同对象
    printf("&e1=%p\n", &e1);
    printf("&e2=%p\n", &e2);

    return 0;
}