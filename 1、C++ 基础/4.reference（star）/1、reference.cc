#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

void test()
{
    // 引用是一个变量的别名，引用在定义的时候必须初始化
    // 引用特点：引用提出的目的是为了减少指针的使用
    int number = 10;

    // 引用的定义写法
    int &ref = number;

    // int &ref;//error,引用在定义的时候必须进行初始化

    // 打印二者内容，输出都为10
    cout << "number=" << number << endl;
    cout << "ref=" << ref << endl;

    // 指向同一块空间
    printf("&number=%p\n", &number);
    printf("&ref=%p\n", &ref);

    /*
    注：如果在'&ref'前有类型，称之为引用；如果没有，即取地址
    */

    cout << endl;

    // 操作引用和操作实体本质上相同
    int num2 = 200;
    ref = num2; // 引用现在成为num2的别名

    cout << "number=" << number << endl;
    cout << "num2=" << num2 << endl;
    cout << "ref=" << ref << endl;

    printf("&number=%p\n", &number);
    printf("&num2=%p\n", &num2); // 引用的地址只与第一次初始化的地址有关
    printf("&ref=%p\n", &ref);

    /*
        引用的本质就是指针，不能改变指向。等于一个指针常量（* const）
        引用在定义的时候必须进行初始化，不能单独存在，否则会报错
        在初始化的时候，必须绑定到变量上，一经绑定，不会改变指向
    */
}

/*
    引用的作用：
        1.可以作为函数的参数
        2.可以作为函数的返回类型
*/

#if 0 // 交换函数无法满足交换需求
//值传递，仅仅是传递副本
//开销比较大
void swap(int x, int y) // int x=a,int y=b
{
    int tmp = x;
    x = y;
    y = tmp;
}
#endif

#if 0
// 通过指针进行操作
//指针传递or地址传递
//直观性不好
void swap(int *px, int *py) // int *px=&a,int *py=&b
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
#endif

// 可以作为函数的参数

// 引用传递
// 操作实体和操作引用是一样的效果
void swap(int &x, int &y) // int &x=a,int &y=b
{
    int tmp = x;
    x = y;
    y = tmp;
}

void test2()
{
    int a = 3, b = 4;
    cout << "swap before a=" << a << ",b=" << b << endl;

#if 0
    swap(a, b); // 交换失败
#endif

#if 0
    swap(&a, &b);//通过指针的形式完成交换
#endif

    swap(a, b); // 引用和指针都可以进行交换

    cout << "swap after a=" << a << ",b=" << b << endl;
}

int func2()
{
    int number = 10;
    return number;
}

// 可以作为函数的返回类型
#if 0
int &func()
{
    int number = 10;
    return number; // 不应该返回局部变量的引用
}
#endif

#if 0
// 函数的返回结果使用引用的前提：实体的生命周期大于函数的生命周期
int arr[5] = {1, 2, 3, 4, 5};
int &getIndex(int idx)
{
    return arr[idx];
}

void test3()
{
    cout << "getIndex(1)=" << getIndex(1) << endl;
    getIndex(1) = 100;//getIndex(1)代表arr[1]
    cout << "getIndex(1)=" << getIndex(1) << endl;
    cout << "arr[1]=" << arr[1] << endl;
}
#endif

// 尽量不要使用堆空间，可能发生内存泄漏问题，如果一定要返回堆空间的引用，必须要有内存自动回收机制
int &getHeapData()
{
    int *pInt = new int(200);
    return *pInt;
}

void test4()
{
    int a = 1, b = 5;
    int c = a + getHeapData() + b; // 内存泄漏
    cout << "c=" << c << endl;

    // 将ref与堆空间联系到一起
    int &ref = getHeapData();
    cout << "ref=" << ref << endl;

    delete (ref); // 解决内存泄漏的问题
}

int main()
{
    // test();
    // test2();
    // test3();
    test4();
    return 0;
}