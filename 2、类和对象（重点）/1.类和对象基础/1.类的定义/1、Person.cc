#include <iostream>
#include <string.h>
using namespace std;

// 类定义没有"()"
class Person
{

    // public\private\protect中添加函数和变量都可以
public: // 公有
    // 函数、变量（成员函数、数据成员）
    // 方法、行为（函数）
    void pay(float money);
    float get();

protected: // 自己使用
           // 私有，不对外提供
private:   // 体现封装
    // 属性、表明的特征（变量）
    char name[20];
    int age;
    float money;
};

#if 0 // 结构总结
class 类名
{

public:
    \\数据成员
    \\成员函数

        protected :
    \\数据成员
    \\成员函数

        private :
    \\数据成员
    \\成员函数
};
#endif

int main()
{
    return 0;
}
