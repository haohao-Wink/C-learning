#include <iostream>

/*
    #pragma pack(4)//一行最多存储四个字节
*/

using std ::cout;
using std::endl;

/*
    内存对齐：
        1.数据成员本身对齐，每个数据成员都要对齐
        2.结构体也要对齐，最后结构体的大小是结构体中最大数据成员的整数倍
        3.结构体中包含结构体，内部结构体要对齐，且内部结构体也要满足对齐规则（按照最大数据成员整数倍开始对齐）
*/

struct x
{
    char a;  // 1,存储在0号位置
    int b;   // 4，存储在4、5、6、7号位置
    short c; // 2，存储在8、9号位置
    char d;  // 1，存储在10号位置
} MyStructx; // 12，根据最大数据成员的整数倍进行对齐

struct y
{
    int b;
    char a;
    char d;
    short c;
} MyStructy; // 8

struct SS
{
    int a;
    char b;
    short c;
    int d;
    struct FF
    {
        int a1;
        char b1;
        short c1;
        char d1;
    } MtStructFF;

    // int e;
    char e; // 28
    // double ww; // 8
} MyStructSS; // 40

struct DD
{
    int a;
    char b;
    short c;
    int d;

    struct FF
    {
        double a1;
        char b1;
        short c1;
        char d1;
    } MystructFF; // 根据结构体独立进行计算

    char e;
} MyStructDD; // 40

struct GG
{
    char e[2];
    short h;
    struct
    {
        int a; // 按照最大内存整数倍来存储
        double b;
        float c;
    } MyStructA;
} MyStructGG; // 32

int main()
{
    cout << "sizeof(MyStructx)=" << sizeof(MyStructx) << endl;
    cout << "sizeof(MyStructy)=" << sizeof(MyStructy) << endl;
    cout << "sizeof(MyStructSS)=" << sizeof(MyStructSS) << endl;
    cout << "sizeof(MyStructDD)=" << sizeof(MyStructDD) << endl;
    cout << "sizeof(MyStructGG)=" << sizeof(MyStructGG) << endl;
    return 0;
}