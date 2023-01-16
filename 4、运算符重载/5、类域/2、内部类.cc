#include <iostream>
#include <limits>

using std::cout;
using std::endl;

class Line
{
public:
    Line(int x1, int y1, int x2, int y2)
        : _pt1(x1, y1), _pt2(x2, y2)
    {
        cout << "Line(int, int, int, int)" << endl;
    }

    void printLine() const
    {
        _pt1.print();
        cout << "---->";
        _pt2.print();
        cout << endl;
    }

    ~Line()
    {
        cout << "~Line()" << endl;
    }

private:
    // Point是Line的内部类,嵌套类
    class Point
    {
    public:
        Point(int ix = 0, int iy = 0)
            : _ix(ix), _iy(iy)
        {
            cout << "Point(int = 0, int = 0)" << endl;
        }

        void print() const
        {
            cout << "(" << this->_ix
                 << ", " << this->_iy
                 << ")";
        }

        ~Point()
        {
            cout << "~Point()" << endl;
        }

    private:
        int _ix;
        int _iy;
    }; // end of point

private:
    Point _pt1;
    Point _pt2;
};

void test()
{
#if 0
    Line::Point pt1(1, 2);//私有的,error
#endif

    Line line(1, 2, 3, 4);
    cout << "line = ";
    line.printLine();
    cout << endl;
}

int main()
{
    test();
    return 0;
}
