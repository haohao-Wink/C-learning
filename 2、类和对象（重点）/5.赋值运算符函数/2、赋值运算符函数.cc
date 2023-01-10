#include <iostream>
using std ::cout;
using std ::endl;

// 类的声明
class Computer
{
public:
    Computer(const char *name, float price);

    Computer(const Computer &rhs);

    Computer &operator=(const Computer &rhs);

    void setBrand(const char *name);
    void setPrice(float price);
    void print();

    ~Computer();

private:
    // 内存对齐
    char *_name;
    float _price;
};

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

// 深拷贝，可以解决double free问题
Computer ::Computer(const Computer &rhs)
    : _name(new char[strlen(rhs._name) + 1]()), _price(rhs._price)
{
    cout << "Computer(const Computer &)" << endl;
    strcpy(_name, rhs._name);
}

#if 0 
// 赋值运算符函数
com2 = com1; // 可能会导致内存泄漏且两个指针指向同一块空间
Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;

    // 赋值
    this->_name = rhs._name;
    this->_price = rhs._price;

    return *this; // 返回对象本身，进行解引用
}
#endif

// 如果自己复制给自己，会指向空指针
Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;

    // 赋值运算符函数四部曲

    // 1.自复制问题（考虑自己复制给自己）
    if (this != &rhs) // 防止自己复制给自己报错，指向空指针
    {
        // 2.释放左操作数
        // 目的：解决内存泄漏的问题
        //   销毁原指针
        delete[] _name;
        _name = nullptr;

        // 3.深拷贝
        //  目的：解决double free（浅拷贝）的问题

        //   开辟新空间
        _name = new char[strlen(rhs._name) + 1]();

        // 进行拷贝
        strcpy(_name, rhs._name);
        _price = rhs._price;

        this->_name = rhs._name;
        this->_price = rhs._price;
    }

    // 4.返回 *this
    return *this;
} // end of 赋值运算符函数

// 类名和作用域限定符表示
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
    Computer com1("lenovo", 5300);
    cout << "com1:" << endl;
    com1.print();

    cout << endl;
    Computer com2("thinkpad", 6600);
    cout << "com2:" << endl;
    com2.print();

    cout << endl;

    com2 = com1;

    cout << "com1:" << endl;
    com1.print();

    cout << "com2:" << endl;
    com2.print();
}

int main()
{
    test();
    return 0;
}