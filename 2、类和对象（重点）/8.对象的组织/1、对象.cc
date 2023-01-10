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

    // 将函数改为const版本，才可以被const对象调用
    void print() const
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

void test() // const对象
{
    // 默认情况下，非const对象调用非const版本的成员函数，const对象调用const版本的成员函数
    // 非const对象也可以调用const版本的成员函数,const对象不能调用非const版本的成员函数

    Point pt(11, 22);
    cout << "pt:" << endl;
    pt.print();

    cout << endl;
    // const int num=10;
    const Point pt1(44, 55);
    cout << "pt1:" << endl;
    pt1.print();
}

void test1() // 指向对象的指针
{
    // p是连接堆空间的指针，p位于栈，指向堆
    Point *p = new Point(2, 3); // 堆对象
    p->print();

    // 堆空间需要程序员手动释放
    delete p;
    p = nullptr; // 第一个执行析构函数
} // end of test

void test2() // 对象数组
{
    // 数组
    Point pt[5] = {Point(1, 2), Point(3, 4), Point(5, 6)};

#if 0 // 另一种初始化方法
    Point pt[5] = {{1, 2}, {3, 4}, {5, 6}};
#endif

#if 0
    // 逗号表达式：以最后一个逗号后面的值代表括号中的内容
    Point pt[5] = {(1, 2), (3, 4), (5, 6)};

    pt[0].print();2,0
    pt[1].print();4,0
    pt[2].print();6,0
#endif
}

void test3() // 堆对象
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
    // test1();
    //  test2();
    //  test3();
    return 0;
}
