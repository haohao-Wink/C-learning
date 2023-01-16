#include <iostream>

using std::cout;
using std::endl;

/*
    作用域与可见域：
        作用域大于等于可见域；如果没有发生屏蔽现象，作用域与可见域相同
*/
int num = 10;

namespace wd
{
    int num = 20;
    class Test
    {
    public:
        Test(int value = 100)
            : num(value) {}

        // 屏蔽
        void print(int num)
        {
            cout << "can shu num=" << num << endl;
            cout << "shu ju cheng yuan num=" << this->num << endl;
            cout << "shu ju cheng yuan num=" << Test::num << endl;
            cout << "wd num=" << wd::num << endl;
            cout << "quan ju num=" << ::num << endl;
        }

    private:
        int num;
    };
} // end of namespace wd

void test()
{
    int value = 1000;
    wd::Test tst;
    tst.print(value);
}

int main()
{
    test();
    return 0;
}