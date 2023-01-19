#include <iostream>

using std::cout;
using std::endl;

class Grandpa
{
public:
    // 第四步，执行grandpa
    Grandpa()
    {
        cout << "Grandpa()" << endl;
    }

    virtual void func1()
    {
        cout << "void Grandpa::func1()" << endl;
    }

    virtual void func2()
    {
        cout << "void Grandpa::func2()" << endl;
    }

    // 第十步，执行对象销毁
    ~Grandpa()
    {
        cout << "~Grandpa()" << endl;
    }
};

class Father
    : public Grandpa
{
public:
    // 第三步，继承grandpa
    Father()
    {
        // 第五步，执行father构造函数
        cout << "Father()" << endl;
        this->func1(); // 调用father是因为son还没出现
    }

    virtual void func1()
    {
        cout << "void Father::func1()" << endl;
    }

    virtual void func2()
    {
        cout << "void Father::func2()" << endl;
    }

    ~Father()
    {
        // 第九步，执行对象销毁
        cout << "~Father()" << endl;
        this->func2(); // son已经销毁，执行自己的
    }
};

class Son
    : public Father
{
public:
    // 第二步，调用father的构造函数
    Son()
    {
        // 第六步，执行son构造函数
        cout << "Son()" << endl;
    }

    virtual void func1()
    {
        cout << "void Son::func1()" << endl;
    }

    virtual void func2()
    {
        cout << "void Son::func2()" << endl;
    }

    ~Son()
    {
        // 第七步，执行对象销毁
        cout << "~Son()" << endl;
    }
};

int main()
{
    // 第一步
    Son son; // 栈对象
    return 0;
}