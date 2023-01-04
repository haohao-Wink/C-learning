#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

// 指针与引用的区别：

void test()
{
    // 引用是一个变量的别名，引用在定义的时候必须初始化
    // 引用特点：引用提出的目的是为了减少指针的使用
    int number = 10;
    int &ref = number;
    cout << "number=" << number << endl;
    cout << "number" << ref << endl;
    printf("&number=%p\n", &number);
    printf("&ref=%p\n", &ref);

    cout << endl;

    // 操作引用和操作实体本质上相同
    int num2 = 200;
    // 引用现在成为num2的别名
    ref = num2;
    cout << "number=" << number << endl;
    cout << "number" << ref << endl;
    cout << "num2=" << num2 << endl;

    // 引用的本质就是指针，不能改变指向。等于一个指针常量（* const）
    // 引用在定义的时候必须进行初始化，不能单独存在，否则会报错
    // 在初始化的时候，必须绑定到变量上，一经绑定，不会改变指向
    // int &ref2;//error
}

void test1()
{
}

// 值传递，副本
// 开销比较大

// 指针传递
// 直观性不好
void swap(int *px, int *py) // int x=a,int y=4;
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

//     可以作为函数的返回类型
void test2()
{
    int a = 3, b = 4;
    cout << "交换之前a=" << a << ",b=" << b << endl;
    swap(&a, &b);
    cout << "交换之前a=" << a << ",b=" << b << endl;
}

int main()
{
    test2();
    return 0;
}

// 指针
//     可以作为函数的参数

#if 0
void swap(int x, int y) // int x=a,int y=4;
{
    int tmp = x;
    x = y;
    y = tmp;
}
#endif

// 引用传递
// 操作实体与操作引用是一样的效果
int &func()
{
    int number = 10;
    return number;
}

// 不要返回局部变量引用

int arr[5] = {1, 2, 3, 4, 5};
int &getIndex(int idx)
{
    return arr[idx];
}

// 函数的返回结果使用引用的前提：实体的生命周期大于函数的生命周期

int &getHeapData()
{
    int *pInt = new int(200);
    return *pInt;
}

// 尽量不要使用堆空间，可能发生内存泄漏问题，如果一定要返回堆空间的引用，需要自动完成内存释放