#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{
public:
    String() // 无参构造函数
        : _pstr(nullptr)
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String &rhs)
        : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        // 1.自复制
        if (this != &rhs)
        {
            // 2.释放左操作数
            delete[] _pstr;
            _pstr = nullptr;

            // 3.深拷贝
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }

        // 4.返回*this
        return *this;
    }

    ~String()
    {
        cout << "~String" << endl;
        if (_pstr)
        {
            delete[] _pstr;
            _pstr = nullptr;
        }
    }

    void print()
    {
        if (_pstr) // 指针判空
        {
            cout << "_pstr=" << _pstr << endl;
        }
    }

    size_t length() const
    {
        size_t len = 0;
        if (_pstr)
        {
            len = strlen(_pstr);
        }
        return len;
    }

    const char *c_str() const
    {
        if (_pstr)
        {
            return _pstr;
        }
        else
        {
            return nullptr;
        }
    }

private:
    char *_pstr;
}; // end of class

int main()
{
    String str1;
    str1.print();

    cout << endl
         << endl;

    String str2 = "hello world"; // C风格字符串转C++风格字符串，类型不匹配，生成临时string，再赋值
    String str3("wangdao");      // 初始化

    str2.print();
    str3.print();

    cout << endl
         << endl;

    String str4 = str3; // 拷贝构造函数
    str4.print();

    cout << endl
         << endl;
    str4 = str2; // 赋值运算符函数
    str4.print();

    // 从C++风格字符串转变为C风格字符串
    const char *pstr = str3.c_str();

    return 0;
}