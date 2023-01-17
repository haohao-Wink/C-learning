#include "Line.h"
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl
{
public:
    LineImpl(int x1, int y1, int x2, int y2);
    void printLineImpl() const;

private:
    class Point
    {
    public:
        Point(int x = 0, int y = 0)
            : _x(x), _y(y) {}

        void print() const;

    private:
        int _x;
        int _y;
    };

    Point _pt1;
    Point _pt2;
};

Line::LineImpl::LineImpl(int x1, int y1, int x2, int y2)
    : _pt1(x1, y1), _pt2(x2, y2) {}

void Line::LineImpl ::printLineImpl() const
{
    _pt1.print();
    cout << "--->";
    _pt2.print();
    cout << endl;
}

Line::Line(int x1, int y1, int x2, int y2)
    : _pimpl(new LineImpl(x1, y1, x2, y2)) {}

Line::~Line()
{
    delete _pimpl;
}

void Line::printLine() const
{
    _pimpl->printLineImpl();
}