#include <iostream>

using std::cout;
using std ::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix), _iy(iy) // 常量应该在初始化列表中进行初始化成员变量
    {
        cout << "Point(int=0,int=0)" << endl;

#if 0
        _ix(ix), _iy(iy)//error，常量不能进行赋值，只能读
#endif
    }

    void print(/*  " Point *const this"  */)
    {

        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    // 常量数据成员
    const int _ix;
    const int _iy;
};

void test()
{
}

int main()
{
    test();
    return 0;
}
