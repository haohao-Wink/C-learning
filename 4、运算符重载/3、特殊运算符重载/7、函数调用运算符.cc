#include <iostream>

using std ::cout;
using std::endl;

class FunctionObject
{
public:
    FunctionObject()
        : _cnt(0) {}

    int operator()(int x, int y)
    {
        cout << "int operator ()(int ,int)" << endl;
        ++_cnt;
        return x + y;
    }

    int operator()(int x, int y, int z)
    {
        cout << "int operator ()(int ,int ,int )" << endl;
        ++_cnt;
        return x * y * z;
    }

private:
    int _cnt; // 函数对象的状态

}; // end of class

// c语言中的面向过程
int add(int x, int y)
{
    static int cnt = 0;
    ++cnt;
    cout << "int add(int ,int)" << endl;
    return x + y;
}

int main()
{
    // C++中的面向对象
    FunctionObject fo;
    int a = 3, b = 4, c = 5;

    // fo.operator()(a,b)=====>fo(a,b);
    // fo.operator()(a,b,c)=====>fo(a,b,c);

    // 函数对象：重载了函数调用运算符的类创建的对象
    cout << "fo(a,b)=" << fo(a, b) << endl;
    cout << "fo(a,b,c)=" << fo(a, b, c) << endl;

    cout << "add(a,b)=" << add(a, b) << endl;

    return 0;
}