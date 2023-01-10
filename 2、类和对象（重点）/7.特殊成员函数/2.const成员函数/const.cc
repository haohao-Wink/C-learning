#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

class Computer
{
public:
    Computer(const char *name, float price);
    void setBrand(const char *name);
    void setPrice(float price);
    void print();

    // 函数重载
    void print() const; // 建议先写const版本的成员函数

    ~Computer();

private:
    char *_name;
    float _price;
}; // end of computer

// 构造函数
Computer::Computer(const char *name, float price)
    : _name(new char[strlen(name) + 1]()) // 将指针指向堆空间
      ,
      _price(price)
{
    cout << "Computer(const char *,float)" << endl;

#if 0 // 和初始化同义
    _name=new char[strlen(name)+1]();//+1是保证'\0'
#endif

    strcpy(_name, name);
}

void Computer::print(/*Computer *const this*/)
{
    cout << "void print()" << endl;

    if (_name)
    {
        cout << "name=" << _name << endl;
        cout << "price=" << _price << endl;
    }
}

// 函数之所以可以重载，是因为地址指针也即参数列表不同
// 只读不写
void Computer::print(/*Computer const *const this*/) const
{
    cout << "void print() const " << endl;

#if 0 
    this=nullptr;//error,不能改变指针指向
    this->price=1000;//error,不能改变指针内容
#endif

    if (_name)
    {
        cout << "name=" << _name << endl;
        cout << "price=" << _price << endl;
    }
}

// 析构函数
Computer::~Computer()
{
    cout << "~Computer()" << endl;

    // 判断空指针
    if (_name) // if(_name!=nullptr)
    {
        delete[] _name; // 防止内存泄漏
        _name = nullptr;
    }
}

void test()
{
    // 默认情况下，非const对象调用非const版本的成员函数，const对象调用const版本的成员函数
    // 非const对象也可以调用const版本的成员函数,const对象不能调用非const版本的成员函数

    Computer com1("lenovo", 5300);
    cout << "com1:" << endl;
    com1.print();

    cout << endl;
    // const int num=10;
    const Computer com2("thinkpad", 6600);
    cout << "com2:" << endl;
    com2.print();
}

int main()
{
    test();
    return 0;
}
