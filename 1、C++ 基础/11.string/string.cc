#include <iostream>

// 方便使用memset
#include <string.h> //C的头文件
#include <stdlib.h>

#include <string> //C++的头文件

using std ::cout;
using std ::endl;

using std::string; // 引出string的实体

// 补充：数组名是数组的入口地址，函数名是函数的入口地址

void test()
{

#if 0
    // 字符数组,结尾包含"\0"

    char str1[] = "hello";
    size_t len1 = sizeof(str1);
    printf("len1=%lu\n", len1);
    // 输出为6，因为字符串中包含 ‘/0’

    //对于字符数组，可以改变数组内容，但不能改变指针指向
    str1[0] = 'H';//可以改变数组里的内容
    str1 = 3;//error
#endif

#if 0

    // 字符指针(常量指针)
    // 可以改变指向，不能改变内容

    const char *pstr = "hello world";

    pstr[0] = 'H'; // error，不能给常量指针赋初值
    printf("pstr=%s\n", pstr);

    pstr = "12345";
    printf("pstr=%s\n", pstr);
   
   
    // 对于指针而言，直接采用sizeof，测试的是指针长度
    size_t len2 = sizeof(pstr);
    printf("len2=%lu\n", len2);

    size_t len3 = strlen(pstr);
    printf("len3=%lu\n", len3);

    // 出现不报错的问题，在每一行末尾进行输出，进行检查错误

#endif

#if 0
    char str1[] = "hello";
    char str2[] = ",world";

// C语言中拼接字符串

     // 将str1和str2连接成一个字符串
    // 首先申请一个空间str3，然后将str1拷贝到str3，最后将str2连接到str3之后

    size_t len4 = sizeof(str1);
    size_t len5 = sizeof(str2);
    char *pstr2 = static_cast<char *>(malloc(len4 + len5 - 1));
    memset(pstr2, 0, len4 + len5 - 1);
    strcpy(pstr2, str1);
    strcat(pstr2, str2);
    printf("pstr2=%s\n", pstr2);

    free(pstr2);
    pstr2=nullptr;//防止野指针

#endif
}

// C++模式下字符串拼接
void test2()
{
    string s1 = "hello";
    string s2 = ",world";
    string s3 = s1 + s2;

// 字符串拼接
#if 0   
    string s3 = s1 + s2; // 不需要考虑内存、长度
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;
#endif

// 查询字符串长度
#if 0
    //size_t可以理解为无符号的Int
    size_t len1 = s1.length();
    size_t len2 = s2.length();
    size_t len3 = s3.length();

    cout << "len1=" << len1 << endl;
    cout << "len2=" << len2 << endl;
    cout << "len3=" << len3 << endl;
#endif

// 字符串其他拼接方法
#if 0
    // 简单直接拼接，不需要考虑长度
    string s4 = s3 + "aaaaa";
    cout << "s4=" << s4 << endl;

    string s5 = s4 + 'A';
    cout << "s5=" << s5 << endl;

    //添加s1到s5之后
    s5.append(s1);
    cout << "s5=" << s5 << endl;
#endif
}

int main()
{
    test();
    test2();
    return 0;
}
