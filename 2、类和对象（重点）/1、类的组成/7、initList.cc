#include <iostream>

using std::cout;
using std::endl;

class Test
{
public:
    // 数据成员的初始化与其在初始化列表中的顺序没有关系，与数据成员在声明中的顺序有关
    Test(int value)
        : _iy(value), _ix(_iy) // 初始化列表中对数据成员按照声明顺序进行初始化
    {
        cout << "Test(int)" << endl;
    }

    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    int _iy;
    int _ix;
};

void test()
{
    Test tst(100);
    cout << "tst=";
    tst.print();
}

int main()
{
    test();
    return 0;
}