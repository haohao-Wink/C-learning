#include <iostream>
#include <stdlib.h> //使用malloc
#include <string.h> //使用memset

using std::cout;
using std::endl;

// C与C++混合编程
#if 0
#ifdef __cplusplus // C++中的内置宏
extern "C"         // 可以在C++代码中将函数按照C的方式进行编译
{
#endif             // C语言的编译器不识别，直接跳过

    int add(int x, int y)
    {
        return x + y;
    }

#ifdef __cplusplus
} // end of extern "C"
#endif
#endif

int add(int x, double y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

void test()
{
    // C++在编译的时候，将C的代码按照C进行编译
    int *pInt = static_cast<int *>(malloc(sizeof(int)));
    memset(pInt, 0, sizeof(int));

    free(pInt);
    // pInt = NULL; // 否则会产生野指针
    pInt = nullptr; // C++11版本
}

int main()
{
    test();
    return 0;
}