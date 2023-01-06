#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

/*
malloc和free
new与delete
             相同点：
                都是用来申请堆空间
                都需要成对出现（否则会出现内存泄漏）

                内存泄漏、踩内存、内存踩踏
                macclo底层实现

            不同点：
                malloc/free属于c语言中的库函数，new/delete属于c++中的表达式
                malloc申请的堆空间是原始的未初始化的，new申请的是已经初始化的
*/

// 用来申请和释放堆空间

void test()
{
    int *p1 = (int *)malloc(sizeof(int)); // 申请堆空间（原始的未初始化的堆空间）
    memset(p1, 0, sizeof(int));           // 初始化
    *p1 = 100;                            // 赋值
    free(p1);                             // 释放堆空间
    int *pArray = (int *)malloc(sizeof(int) * 10);
    memset(pArray, 0, sizeof(int) * 10);
    pArray[0] = 10;
    pArray[1] = 20;
}

void test1()
{
    int *pInt = new int(10);
    //*PInt =10;

    delete pInt; // 释放堆空间

    int *pArray = new int[10](); //"()表示初始化"
    pArray[0] = 10;
    pArray[1] = 20;
    delete[] pArray; // 释放堆空间数组
}

int main()
{
    test();
    return 0;
}