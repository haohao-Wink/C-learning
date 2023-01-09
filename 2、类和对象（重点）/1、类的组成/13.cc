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

    Point(const Point &rhs)
        : _ix(rhs._ix), _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    Point &operator=(const Point &rhs)
    {
        cout << "Point &operator=(const Point &)" << endl;

        // 赋值
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;

        return *this; // 返回对象本身，进行解引用
    }

    void print()
    {
        cout << "(" << this->_ix << "," << this->_iy << ")" << endl;
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
    // 数组
    Point pt[5] = {Point(1, 2), Point(3, 4), Point(5, 6)};

#if 0 // 另一种初始化方法
    Point pt[5] = {{1, 2}, {3, 4}, {5, 6}};
#endif

    // 逗号表达式：以最后一个逗号后面的值代表括号中的内容
    // Point pt[5] = {(1, 2), (3, 4), (5, 6)};

    pt[0].print();
    pt[1].print();
    pt[2].print();
}

void test2()
{
    Point *pt = new Point(1, 2); // 堆对象
    pt->print();
    delete pt;
    pt = nullptr;

    cout << endl
         << endl;
    Point *pArray = new Point[10]();
    pArray[0] = {1, 2};

    // 固定数组删除格式
    delete[] pArray; // new,delete应该成对出现
    pArray = nullptr;
}

int main()
{
    // test();
    test2();
    return 0;
}
