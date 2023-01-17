#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
        : _pstr(new char[5]() + 4)
    {
        cout << "String()" << endl;
        initRefCount();
    }

    String(const char *pstr)
        : _pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
        initRefCount();
    }

    // String s2 = s1;
    String(const String &rhs)
        : _pstr(rhs._pstr)
    {
        cout << "String(const String &)" << endl;
        increseRefCount();
    }

    // s3 = s1;
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        // 1、自复制
        if (this != &rhs)
        {
            // 2、释放左操作数
            release();

            // 3、浅拷贝
            _pstr = rhs._pstr;
            increseRefCount();
        }

        // 4、返回*this
        return *this;
    }

    // s3 = s1;
    // s3[0] = 'H'
    char &operator[](size_t idx)
    {
        if (idx < size())
        {
            if (getRefCount() > 1) // 共享的
            {
                // 深拷贝
                char *tmp = new char[size() + 5]() + 4;
                strcpy(tmp, _pstr);
                // 引用计数--
                descreRefCount();

                // 浅拷贝
                _pstr = tmp;
                // 初始化引用计数
                initRefCount();
            }
            return _pstr[idx];
        }
        else
        {
            static char charNull = '\0';
            return charNull;
        }
    }

    ~String()
    {
        cout << "~String()" << endl;
        release();
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

private:
    size_t size() const
    {
        return strlen(_pstr);
    }

    void initRefCount()
    {
        *(int *)(_pstr - 4) = 1;
    }

    void increseRefCount()
    {
        ++*(int *)(_pstr - 4);
    }

    void descreRefCount()
    {
        --*(int *)(_pstr - 4);
    }

    // 释放
    void release()
    {
        descreRefCount();
        if (0 == getRefCount())
        {
            delete[] (_pstr - 4);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;
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
    cout << "s1 = " << s1 << endl;
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    printf("s1'address = %p\n", s1.c_str());

    cout << endl
         << endl;
    String s2 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    printf("s1'address = %p\n", s1.c_str());
    printf("s2'address = %p\n", s2.c_str());

    cout << endl
         << endl;
    String s3("world");
    cout << "s3 = " << s3 << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
    printf("s3'address = %p\n", s3.c_str());

    cout << endl
         << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
    printf("s1'address = %p\n", s1.c_str());
    printf("s2'address = %p\n", s2.c_str());
    printf("s3'address = %p\n", s3.c_str());

    cout << endl
         << "对s3[0]执行写操作" << endl;
    s3[0] = 'H'; // char = char
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
    printf("s1'address = %p\n", s1.c_str());
    printf("s2'address = %p\n", s2.c_str());
    printf("s3'address = %p\n", s3.c_str());

    cout << endl
         << "对s1[0]执行读操作" << endl;
    cout << "s1[0] = " << s1[0] << endl; // cout << s1[0];
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s1.getRefCount() = " << s1.getRefCount() << endl;
    cout << "s2.getRefCount() = " << s2.getRefCount() << endl;
    cout << "s3.getRefCount() = " << s3.getRefCount() << endl;
    printf("s1'address = %p\n", s1.c_str());
    printf("s2'address = %p\n", s2.c_str());
    printf("s3'address = %p\n", s3.c_str());
}

int main(int argc, char **argv)
{
    test();
    return 0;
}
