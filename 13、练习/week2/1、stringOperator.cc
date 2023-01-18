#include <iostream>
#include <string.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
    区分左值和右值：
        1. 右值无法取地址
        2. 右值通常没有命名
 */

/*
        "hello"===>String("hello")是否等价？
            1. 左边的为C风格字符串，右边为C++风格字符串
            2. 左边为左值，右边为右值
*/

class String
{
public:
    String()
        : _pstr(new char[1]()) // 初始化为'\0'
    {
        cout << "String()" << endl;
    }

    // String s1("hello")
    // String s1="hello";右边是C风格字符串，二者需要通过调用拷贝构造函数对应；由临时对象对s1进行初始化
    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    // String s2(s1) <======>String s2=s1;
    String(const String &rhs)
        : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String (const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    ~String()
    {
        cout << "~String()" << endl;
        if (_pstr)
        {
            delete[] _pstr;
            _pstr = nullptr;
        }
    }

    // String s1;s1=s1;
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if (this != &rhs)
        {
            delete[] _pstr;
            _pstr = nullptr;

            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    // s1="hello"
    String &operator=(const char *pstr)
    {
        cout << "String &operator =(const char *)" << endl;
        String t(pstr);
        *this = t;

        return *this;
    }

    // s1+=s2;
    String &operator+=(const String &rhs)
    {
        cout << "String &operator +=(const String &)" << endl;
        String t;
        if (t._pstr)
        {
            delete[] t._pstr; // 防止内存泄漏
        }

        t._pstr = new char[strlen(_pstr) + 1]();
        strcpy(t._pstr, _pstr);
        delete[] _pstr;

        _pstr = nullptr;
        _pstr = new char[strlen(rhs._pstr) + strlen(t._pstr) + 1]();
        strcpy(_pstr, t._pstr);
        strcat(_pstr, rhs._pstr);
        return *this;
    }

    // s1+="hello"
    String &operator+=(const char *pstr)
    {
        cout << "String &operator+=(const char *)" << endl;
        String t(pstr);
        *this += t;

        return *this;
    }

    // const String s1("hello");
    // s1[0]
    char &operator[](std::size_t index) // index>0
    {
        if (index < size())
        {
            return _pstr[index];
        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }

    const char &operator[](std ::size_t index) const
    {
        if (index < size())
        {
            return _pstr[index];
        }
    }

private:
    char *_pstr;
};