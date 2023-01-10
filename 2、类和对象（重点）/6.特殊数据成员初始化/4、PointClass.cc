#include <iostream>

using std::cout;
using std ::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix), _iy(iy)
    {
        cout << "Point(int=0,int=0)" << endl;
    }

    void print()
    {

        cout << "(" << this->_ix << "," << this->_iy << ")";
    }

    ~Point() // 析构函数
    {
        cout << "~point()" << endl;
    }

private:
    int _ix;
    int _iy;
}; // end of class Point

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
        // 如果不显示初始化，会走子对象的默认构造函数，所以最好可以显示初始化子对象，即显示调用子对象的构造函数
        : _pt1(x1, y1), _pt2(x2, y2) // 对数据进行初始化
    {
    }
    void printLine()
    {

        _pt1.print();
        cout << "=================================";
        _pt2.print();
        cout << endl;
    }

private:
    // 类对象数据成员，子对象
    Point _pt1;
    Point _pt2;
}; // ned of class Line

void test()
{
    Line line(1, 2, 3, 4); // 防止出现随机值
    cout << "line=";
    line.printLine();
}

int main()
{
    test();
    return 0;
}
