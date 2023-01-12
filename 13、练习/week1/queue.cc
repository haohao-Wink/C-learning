#include <iostream>

using std ::cout;
using std::endl;

class Queue
{
public:
    Queue(int size = 10)
        : _size(size), _front(0), _rear(0), _data(new int[_size]())
    {
        cout << "Queue(int =10" << endl;
    }

    bool full() const
    {
        return (_front == (_rear + 1) % _size);
    }

    bool empty() const
    {
        return _front == _rear;
    }

    void push(const int &value)
    {
        if (!full())
        {
            _data[_rear++] = value;
            _rear %= _size;
        }
        else
        {
            cout << "the queue is full" << endl;
            return;
        }
    }

    void pop()
    {
        if (!empty())
        {
            ++_front;
            _front %= _size;
        }
        else
        {
            cout << "the queue is empty" << endl;
            return;
        }
    }

    int front()
    {
        return _data[_front];
    }

    int back()
    {
        return _data[(_rear - 1 + _size) % _size];
    }

    ~Queue()
    {
        cout << "~Queue()" << endl;
        if (_data)
        {
            delete[] _data;
            _data = nullptr;
        }
    }

private:
    int _size;
    int _front;
    int _rear;
    int *_data;
}; // end of class

int main()
{
    Queue que;
    cout << "is the queue empty?" << que.empty() << endl;

    que.push(1);
    cout << "is the queue full?" << que.full() << endl;

    for (int idx = 2; idx != 15; ++idx)
    {
        que.push(idx);
    }

    while (!que.empty())
    {
        cout << que.front() << endl;
        que.pop();
    }

    cout << "is the queue empty?" << que.empty() << endl;
    return 0;
}