#include <iostream>
#include <string>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

/*
    注：
        1. Ubuntu 1404使用写时复制cow
        2. Ubuntu 1808使用短字符串优化sso
            当字符串长度小于16字节，存放在栈上；当字符串长度大于16字节，放在堆上
*/

void test()
{
    string s1 = "hello";
    string s2(s1);
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    printf("s1'address=%p\n", s1.c_str());
    printf("s2'address=%p\n", s2.c_str());

    cout << endl
         << endl;
    string s3 = "world";
    cout << "s3=" << s3 << endl;
    printf("s3'address=%p\n", s3.c_str());

    cout << endl
         << endl;
    s3 = s1;
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;

    cout << endl
         << endl;
    cout << "s3[0]'write" << endl;
    s3[0] = 'H';
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;
    printf("s1'address=%p\n", s1.c_str());
    printf("s2'address=%p\n", s2.c_str());
    printf("s3'address=%p\n", s3.c_str());
}

int main()
{
    test();
    return 0;
}

/*
    安装命令:
        sudo apt install lrzsz
    linux将文件移出 SZ
    Linux将文件移入 rz
*/