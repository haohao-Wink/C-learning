#include <iostream>
#include <string.h>
#include <stdio.h>

using std ::cout;
using std ::endl;

class String
{
public:
    String()
        // 四个字节的引用计数，一个字节的 '\0';+4是为了让指针指向数据位置
        : _pstr(new char[5]() + 4)
    {
        cout << "String()" << endl;

        // 将字符指针强转为数据指针
        *(int *)(_pstr - 4) = 1; // 解引用得到指针的内容
    }

    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
        *(int *)(_pstr - 4) = 1;
    }

    // String s2=s1;
    String(const String &rhs)
        : _pstr(rhs._pstr)
    {
        cout << "String(const String &)" << endl;
        ++*(int *)(_pstr - 4);
    }

    // s3=s1;
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;

        // 1.自复制
        if (this != &rhs)
        {
            // 2.释放左操作数
            --*(int *)(_pstr - 4);
            if (0 == *(int *)(_pstr - 4))
            {
                delete[] (_pstr - 4);
            }
            // 3.浅拷贝

            _pstr = rhs._pstr;
            ++*(int *)(_pstr - 4);
        }

        // 4.返回*this
        return *this;
    }

    ~String()
    {
        cout << "~String()" << endl;
        --*(int *)(_pstr - 4);
        if (0 == *(int *)(_pstr - 4))
        {
            delete[] (_pstr - 4);
        }
    }

    // 获取引用计数
    int getRefCount() const
    {
        return *(int *)(_pstr - 4);
    }

    // 获取底层的指针
    const char *c_str() const
    {
        return _pstr;
    }

    char &operator[](size_t idx)
    {
        if (idx < size())
        {
            if (getRefCount() > 1) // 共享，需要执行深拷贝
            {
                // 深拷贝
                char *t = new char[size() + 5]() + 4;
                strcpy(t, _pstr);

                // 引用计数减减
                --*(int *)(_pstr - 4);

                // 浅拷贝
                _pstr = t;
                // 引用计数初始化
                *(int *)(_pstr - 4) = 1;
            }
            return _pstr[idx];
        }
        else
        {
            static char charNull = '\0';
            return charNull;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;

    size_t size() const
    {
        return strlen(_pstr);
    }
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    if (rhs._pstr)
    {
        os << rhs._pstr;
    }

    return os;
}

void test()
{
    String s1("hello");
    cout << "s1=" << s1 << endl;
    cout << "s1.getRefCount()=" << s1.getRefCount() << endl;
    printf("s1'addewss=%p\n", s1.c_str());

    cout << endl
         << endl;
    String s2 = s1;
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s1.getRefCount()=" << s1.getRefCount() << endl;
    cout << "s2.getRefCount()=" << s2.getRefCount() << endl;
    printf("s1'addewss=%p\n", s1.c_str());
    printf("s2'addewss=%p\n", s2.c_str());

    cout << endl
         << endl;
    String s3("world");
    cout << "s3=" << s3 << endl;
    cout << "s3.getRefCount()=" << s3.getRefCount() << endl;
    printf("s3'addewss=%p\n", s3.c_str());

    cout << endl
         << endl;
    s3 = s1;
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;
    cout << "s1.getRefCount()=" << s1.getRefCount() << endl;
    cout << "s2.getRefCount()=" << s2.getRefCount() << endl;
    cout << "s3.getRefCount()=" << s3.getRefCount() << endl;
    printf("s1'addewss=%p\n", s1.c_str());
    printf("s2'address=%p\n", s2.c_str());
    printf("s3'addewss=%p\n", s3.c_str());

    cout << endl
         << "s3[0]'write" << endl;
    s3[0] = 'H';
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;
    cout << "s1.getRefCount()=" << s1.getRefCount() << endl;
    cout << "s2.getRefCount()=" << s2.getRefCount() << endl;
    cout << "s3.getRefCount()=" << s3.getRefCount() << endl;
    printf("s1'addewss=%p\n", s1.c_str());
    printf("s2'address=%p\n", s2.c_str());
    printf("s3'addewss=%p\n", s3.c_str());
}

int main()
{
    test();
    return 0;
}