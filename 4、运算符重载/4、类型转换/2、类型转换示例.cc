#include <iostream>

using std::cout;
using std ::endl;

class Point
{

public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix),
          _iy(iy)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    // 进行类型转换
    operator int()
    {
        cout << "operator int()" << endl;
        return _ix + _iy;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
}; // end of class

void test()
{
    Point pt(1, 2); // 栈对象
    cout << "pt=" << pt << endl;

} // end of test

int main()
{
    test();
    return 0;
}
