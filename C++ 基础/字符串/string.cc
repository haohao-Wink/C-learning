#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

// 补充：数组名是数组的入口地址，函数名是函数的入口地址

void test()
{

    // 字符数组,结尾包含"\0"
#if 0
    char str1[] = "hello";
    size_t len1 = sizeof(str1);
    printf("len1=%lu\n", len1);
    // 输出为6，因为字符串中包含 ‘/0’

    //对于字符数组，可以改变数组内容，但不能改变指针指向
    str1[0] = 'H';
    str1 = 3;//error
#endif

    // 字符指针(常量指针)
    // 可以改变指向，不能改变内容
#if 0
    const char *pstr = "hello world";
    // 对于指针而言，直接采用sizeof，测试的是指针长度
    size_t len2 = sizeof(pstr);
    printf("len2=%lu\n", len2);

    size_t len3 = strlen(pstr);
    printf("len3=%lu\n", len3);

    // 出现不报错的问题，在每一行末尾进行输出，会报错
    // pstr[0] = 'H'; // error，不能给常量指针赋初值
    // printf("pstr=%s\n", pstr);

    pstr = "12345";
    printf("pstr=%s\n", pstr);
#endif
}

int main()
{
    test();
    return 0;
}

// 风格字符串与C++风格字符串 19.40