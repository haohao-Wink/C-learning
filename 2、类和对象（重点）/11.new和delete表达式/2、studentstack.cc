

#include <string.h>
#include <stdlib.h> //调用malloc

#include <iostream>

using std ::cout;
using std::endl;

// 要求：只能生成堆对象，不能生成栈对象
// 解决方案：将析构函数设置为私有

class Student
{
public:
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

    static void *operator new(size_t sz)
    {
        cout << "void *operator new(size_t)" << endl;
        void *pret = malloc(sz);
        return pret;
    }

    static void operator delete(void *pret)
    {
        cout << "void operator delete (void *)" << endl;
        free(pret);
    }

    void destroy()
    {

#if 0 // 不能直接执行析构函数，没有将对象本身占用的内存回收
        this->~Student(); // error
#endif

        delete this; // this指针指向对象本身的特点
    }

private:
    int _id;
    char *_name;

    ~Student()
    {
        cout << "~Student()" << endl;
        if (_name)
        {
            delete[] _name;
            _name = nullptr;
        }
    }
};

int main()
{
    Student *pstu = new Student(4201, "lili"); // 堆对象
    pstu->print();

    pstu->destroy();
    return 0;
}
