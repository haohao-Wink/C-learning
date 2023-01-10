#include <iostream>

using std::cout;
using std ::endl;

/*
    构造函数：
        作用：完成数据成员初始化
        构造函数没有返回类型

        如果不自己构建构造函数，编译器会自动生成
        如果自定义了构造函数，编译器就不会生成默认构造函数

        如果想创建无参对象，可以 显示 写出无参构造函数
*/

class Point
{
public:
    // 创建构造函数
    Point()
        // ！！注意初始化列表（初始化表达式）位置
        : _ix(0) // 初始化，称为初始化列表
          ,
          _iy(0)
    {
        cout << "Point()" << endl;

        // 将Point函数中的值进行手动初始化
        _ix = 0, _iy = 0; // 赋值操作
    }

#if 0 // 默认构造函数，是无参的
    Point(){}    //函数名与类名相同，参数列表和内容均为空
#endif

#if 0 // 构造函数可以进行重载
    Point(int ix, int iy)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point(int,int)" << endl;
    }
#endif

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test()
{

    Point pt; // 用类创建对象，会自动调用构造函数；目的是将对象中的数据成员进行初始化
    cout << "pt=";
    pt.print(); // error，如果已经更改构造函数（只添加重载函数，不添加默认构造函数），会因为找不到此函数的构造函数而报错

#if 0
    pt.Point();//error，构造函数不能以对象加点的形式进行调用
#endif

#if 0 // 构造函数重载的示例
    cout << endl;
    Point pt2(3, 4);
    cout << "pt2=";
    pt2.print();
#endif

    cout << endl;
    Point().print(); // 显示调用构造函数会创建对象
} // end of test

int main()
{
    test();
    return 0;
}
