

#include <string.h>
#include <stdlib.h> //调用malloc

#include <iostream>

using std ::cout;
using std::endl;

// 要求：只能生成栈对象，不能生成堆对象
// 解决方案：将operator new设置为私有

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

    ~Student()
    {
        cout << "~Student()" << endl;
        if (_name)
        {
            delete[] _name;
            _name = nullptr;
        }
    }

    static void operator delete(void *pret)
    {
        cout << "void operator delete (void *)" << endl;
        free(pret);
    }

private:
    int _id;
    char *_name;

    static void *operator new(size_t sz)
    {
        cout << "void *operator new(size_t)" << endl;
        void *pret = malloc(sz);
        return pret;
    }
};

int main()
{
    Student stu(4202, "lucy"); // 栈对象
    stu.print();

    /*
        Student *pstu = new Student(4201, "lili"); // 堆对象
        pstu->print();

        delete pstu;
        pstu = nullptr;
    */
    return 0;
}
