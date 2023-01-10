#include <iostream>
using std ::cout;
using std ::endl;

class Computer
{
public:
    Computer(const char *name, float price);

    Computer(const Computer &rhs);

    void setBrand(const char *name);
    void setPrice(float price);
    void print();

    ~Computer();

private:
    char *_name;
    float _price;
};

// 构造函数
Computer::Computer(const char *name, float price)
    : _name(new char[strlen(name) + 1]()) // 将指针指向堆空间

{
    cout << "Computer(const char *,float)" << endl;

#if 0 // 和初始化同义
    _name=new char[strlen(name)+1]();//+1是保证'\0'
#endif

    strcpy(_name, name);
}

#if 0 // 浅拷贝：两个指针指向同一区域
//编译器自动生成，不能满足需求
Computer ::Computer(const Computer &rhs)
    : _name(rhs._name), _price(rhs._price) 
{
    cout << "Computer(const Computer &)" << endl;
}
#endif

// 深拷贝，可以解决double free问题
Computer ::Computer(const Computer &rhs)
    : _name(new char[strlen(rhs._name) + 1]()), _price(rhs._price)
{
    cout << "Computer(const Computer &)" << endl;
    strcpy(_name, rhs._name);
}

void Computer::setBrand(const char *name)
{
    strcpy(_name, name);
}

void Computer::setPrice(float price)
{
    _price = price;
}

void Computer::print(/*Computer *const this*/)
{
    cout << "void print()" << endl;

    if (_name)
    {
        cout << "name=" << _name << endl;
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
    Computer com("lenovo", 5300); // 类创建类对象，栈对象
    com.print();

    cout << endl;

    Computer com2 = com;
    com2.print(); // 先执行析构函数

    cout << endl;
    com2.setBrand("MAC"); // 使用深拷贝之后，改变com2的值不会改变com

    com.print();
    com2.print();
}

int main()
{
    test();
    return 0;
}
