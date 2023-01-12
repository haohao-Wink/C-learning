#include <iostream>
#include <string.h>
#include <stdlib.h> //调用malloc

using std ::cout;
using std::endl;

class Student
{
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

    void operator delete(void *pret)
    {
        cout << "void operator delete (void *)" << endl;
        free(pret);
    }

    void *operator new(size_t sz)
    {
        cout << "void *operator new(size_t)" << endl;
        void *pret = malloc(sz);
        return pret;
    }

private:
    int _id;
    char *_name;
};

int main()
{
    Student stu(4202, "lucy"); // 栈对象
    stu.print();

    return 0;
}
