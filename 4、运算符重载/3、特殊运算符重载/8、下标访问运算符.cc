#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int arr[10] = {1, 3, 5, 7, 9};

class CharArray
{
public:
    CharArray(size_t sz)
        : _size(sz), _data(new char[_size]())
    {
        cout << "CharArray(size_t=10)" << endl;
    }

    // 下标访问运算符
    // 优势：重载的下标访问运算符考虑数组越界问题
    //引用什么时候需要加：
    //1.如果返回类型是类类型时，可以减少拷贝构造函数的执行
    //2.有可能需要一个左值而不是拷贝后的右值
    //3.在连续使用时，加引用
    char &operator[](size_t idx)
    {
        if (idx < _size)
        {
            return _data[idx];
        }
        else
        {
            // 静态变量生命周期大于局部变量
            static char charNull = '\0';
            return charNull;
        }
    }

    ~CharArray()
    {
        cout << "~CharArray()" << endl;
        if (_data)
        {
            delete[] _data;
            _data = nullptr;
        }
    }

    size_t size() const
    {
        return _size;
    }

private:
    size_t _size;
    char *_data;
};

void test()
{
    const char *pstr = "hello world";
    // 加1 是表示'\0'
    // 指针空间使用strlen，指针大小使用sizeof
    CharArray ca(strlen(pstr) + 1);

    for (size_t idx = 0; idx != ca.size(); ++idx)
    {
        ca[idx] = pstr[idx];
        //====> ca.operator[](idx) = pstr[idx];
        ca.operator[](idx) = pstr[idx];
    }

    for (size_t idx = 0; idx != ca.size(); ++idx)
    {
        cout << ca[idx] << " ";
        //====》 cout<<ca.operator[](idx)<<" ";
    }

    cout << endl;
}

int main()
{
    test();
    return 0;
}