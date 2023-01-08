#include <iostream>

using std::cout;
using std ::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix), _iy(iy), _ref(_ix)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    void setX(int x)
    {
        _ix = x;
    }

    void print(/*  " Point *const this"  */)
    {

        cout << "(" << this->_ix << "," << this->_iy << ","
             //<< this->_ref
             << ")" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;

    // 引用占据一个指针大小的空间
    int &_ref; // 引用作为数据成员必须初始化
};

void test()
{
    cout << "sizeof(Point)=" << sizeof(Point) << endl; // 两个int
    // 成员函数不占用类所占据的大小

    Point pt(1, 2); // pt是栈对象
    cout << "Pt=";
    pt.print();

    pt.setX(100);
    cout << "Pt=";
    pt.print();
}

int main()
{
    test();
    return 0;
}
