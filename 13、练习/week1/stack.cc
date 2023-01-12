#include <iostream>
using std ::cout;
using std::endl;

class Stack
{
public:
    Stack(int size = 10) // 构造函数
        : _size(size), _top(-1), _data(new int[_size]())
    {
        cout << "Stack(size=10)" << endl;
    }

    ~Stack() // 析构函数
    {
        cout << "~Stack()" << endl;
        if (_data)
        {
            delete[] _data;
            _data = nullptr;
        }
    }

    bool full() const // 判满
    {
#if 0 // 思路
    if (_top == _size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
#endif
        return (_top == _size - 1);
    }

    bool empty() const // 判空
    {
        return (-1 == _top); // 防止判断写成赋值
    }

    void push(const int &value)
    {
        if (!full())
        {
            _data[++_top] = value;
        }
        else
        {
            cout << "the stack is full" << endl;
            return;
        }
    }

    void pop()
    {
        if (!empty())
        {
            --_top;
        }
        else
        {
            cout << "the stack is empty" << endl;
            return;
        }
    }

    int top() const
    {
        return _data[_top];
    }

private:
    int _size;
    int _top;
    int *_data;
}; // end of class

int main()
{
    Stack st(12);
    cout << "Stack is empty?" << st.empty() << endl;
    st.push(1);
    cout << "Stack is full?" << st.full() << endl;

    for (int idx = 2; idx != 15; ++idx)
    {
        st.push(idx);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "stack is empty?" << st.empty() << endl;

    return 0;
}