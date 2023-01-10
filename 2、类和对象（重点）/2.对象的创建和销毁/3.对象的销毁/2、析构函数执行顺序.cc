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

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test()
{
    Point pt; // 栈对象
    cout << "pt=";
    pt.print();

    // 栈是先入后出的，所以pt2先销毁
    cout << endl;
    Point pt2(3, 4); // 栈对象
    cout << "pt2=";
    pt2.print();
}

int main()
{
    cout << "begin test..." << endl;
    test(); // test执行结束后，执行析构函数（即对象在销毁的时候调用）
    cout << "finish test..." << endl;
    return 0;
}
