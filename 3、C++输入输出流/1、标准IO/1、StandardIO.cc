#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printStreamStatus()
{
    cout << "cin.badbit=" << cin.bad() << endl;
    cout << "cin.failbit=" << cin.fail() << endl;
    cout << "cin.eofbit=" << cin.eof() << endl;
    cout << "cin.goodbit=" << cin.good() << endl;
}

#if 0 // 不能进行连续输入
void test()
{
    int num = 0;
    printStreamStatus(); // cin.goodbit=1
    cin >> num;

    cout << "num=" << num << endl;
    // 输入"hello"
    printStreamStatus(); // failbit=1

    cin.clear(); // 重置流的状态
    // cin.ignore(1024, '\n'); // 清空缓冲区

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    printStreamStatus();

    cout << "num=" << num << endl;

    string line;
    cin >> line;
    cout << "line=" << line << endl;
}
#endif

void test2()
{
    int num = 0;

    // while(真值表达式)
    while (cin >> num, !cin.eof()) // cin>>num返回的是对象
    // 使用逗号表达式进行改进
    {
        if (cin.bad())
        {
            std::cerr << "the stream is bad" << endl;
            return;
        }
        else if (cin.fail())
        {
            cin.clear(); // 重置流的状态

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore调用方式
            cout << "please cin int!!" << endl;
        }
        else
        {
            cout << "num=" << num << endl;
        }
    } // end of while
} // end of test2

int main()
{
    // test();
    test2();
    return 0;
}

/*
    程序重点指令：
        Ctrl c//异常中断
        ctrl d//正常退出
*/