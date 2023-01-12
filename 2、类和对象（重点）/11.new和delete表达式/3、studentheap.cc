#include <iostream>
#include <string.h>
#include <stdlib.h> //调用malloc

using std ::cout;
using std::endl;

class Student
{
public:
    // 执行new表达式第二步，执行构造函数
    Student(int id, const char *name)
        : _id(id), _name(new char[strlen(name) + 1]())
    {
        cout << "Student(int ,const char*)" << endl;
        strcpy(_name, name);
    }

    void print() const
    {
        if (_name)
        {
            cout << "id=" << _id << endl;
            cout << "name=" << _name << endl;
        }
    }

    // 执行delete表达式第一步：执行析构函数
    ~Student()
    {
        cout << "~Student()" << endl;
        if (_name)
        {
            delete[] _name;
            _name = nullptr;
        }
    }

#if 1
    // operator new静态成员函数
    //  void *=======>C语言中的万能指针
    static void *operator new(size_t sz) // 执行new表达式第一步：执行operator new函数
    {
        cout << "void *operator new(size_t)" << endl;

#if 0 // operator new函数中没有this指针
        printf("this:%p\n", this);
#endif

        void *pret = malloc(sz);
        return pret;
    }

    // operator delete 静态成员函数
    //  执行delete表达式第二步：执行operator delete表达式
    static void operator delete(void *pret)
    {

#if 0 // operator delete函数中没有this指针
        printf("this:%p\n", this);
#endif

        cout << "void operator delete (void *)" << endl;
        free(pret);
    }
#endif

private:
    int _id;
    char *_name;
};

int main()
{
    Student *pstu = new Student(4201, "lili");
    pstu->print();

    delete pstu;
    pstu = nullptr;
    return 0;
}
