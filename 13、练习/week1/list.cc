#include <iostream>

using std ::cout;
using std ::endl;

struct Node // 定义结点
{
    // 构造函数
    Node(int data = 0, Node *pre = nullptr, Node *next = nullptr)
        : _data(data), _pre(pre), _next(next)
    {
        cout << "Node(int data=0,Node *pre=nullptr,Node *next=nullptr)" << endl;
    }

    // 析构函数
    ~Node()
    {
        cout << "~Node()" << endl;
    }

    int _data;
    Node *_pre;
    Node *_next;
}; // end of struct

class List // 定义双向链表
{
public:
    List() // List构造函数
        : _head(new Node()), _tail(new Node()), _size(0)
    {
        cout << "List()" << endl;
        _head->_next = _tail;
        _tail->_pre = _head;
    }

    ~List() // List析构函数
    {
        cout << "~List()" << endl;
        Node *deleteNode = _head->_next;
        while (deleteNode) // 删除结点
        {
            Node *ptmp = deleteNode->_next;
            delete deleteNode;
            deleteNode = nullptr;
            deleteNode = ptmp;
        }

        delete _head;
        _head = nullptr;
    }

    void display() const // 打印输出
    {
        if (size() > 0)
        {
            Node *pNode = _head->_next;
            while (pNode && pNode != _tail)
            {
                cout << pNode->_data << " ";
                pNode = pNode->_next;
            }
            cout << endl;
        }
        else
        {
            cout << "the list is empty!!!!!!" << endl;
            return;
        }
    }

    int size() const // 计算大小
    {
        return _size;
    }

    void push_back(int data);       // 尾插法
    void push_front(int data);      // 头插法
    void insert(int pos, int data); // 中间插入

    void pop_front(); // 头删法
    void pop_back();  /// 尾删法

    bool find(int data) // 查找元素
    {
        if (size() > 0)

        {
            Node *pNode = _head->_next;
            while (pNode && pNode != _tail)
            {
                if (data == pNode->_data)
                {
                    return true;
                }

                pNode = pNode->_next;
            }
            return false;
        }
        else
        {
            cout << "list is empty!!!!" << endl;
            return false;
        }
    } // end of bool

    void erease(int data); // 在中间进行删除

private:
    Node *_head;
    Node *_tail;
    int _size;
}; // end of class

void List::push_front(int data)
{
    Node *newNode = new Node(data);
    newNode->_pre = _head;
    newNode->_next = _head->_next;

    // 顺序不可颠倒
    _head->_next->_pre = newNode;
    _head->_next = newNode;

    ++_size;
}

void List::push_back(int data)
{
    Node *newNode = new Node(data);
    newNode->_pre = _tail->_pre;
    newNode->_next = _tail;

    // 顺序不可颠倒
    _tail->_pre->_next = newNode;
    _tail->_pre = newNode;

    ++_size;
}

void List::insert(int pos, int data)
{
    if (pos < 0 || pos > size())
    {
        cout << "the pos is wrong" << endl;
        return;
    }
    Node *pNode = _head;
    while (pos-- > 0)
    {
        pNode = pNode->_next;
    }
    Node *newNode = new Node(data);
    newNode->_pre = pNode;
    newNode->_next = pNode->_next;

    pNode->_next->_pre = newNode;
    pNode->_next = newNode;

    ++_size;
}

void List::pop_front()
{
    if (size() > 0)
    {
        Node *pNode = _head->_next;
        pNode->_next->_pre = _head;
        _head->_next = pNode->_next;

        delete pNode;
        --_size;
    }
    else
    {
        cout << "the list is empty !!!!" << endl;
        return;
    }
}

void List::pop_back()
{
    if (size() > 0)
    {
        Node *pNode = _tail->_pre;
        pNode->_pre->_next = _tail;
        _tail->_pre = pNode->_pre;

        delete pNode;
        --_size;
    }
    else
    {
        cout << "the list is empty !!!!" << endl;
        return;
    }
}

void List::erease(int data)
{
    bool flag = find(data);
    if (flag)
    {
        Node *pNode = _head->_next;
        while (pNode && pNode != _tail)
        {
            if (pNode->_data == data)
            {
                Node *ptmp = pNode->_pre;
                pNode->_next->_pre = ptmp;
                ptmp->_next = pNode->_next;

                delete pNode;
                pNode = nullptr;
                --_size;

                pNode = ptmp;
            }
            pNode = pNode->_next;
        }
    }
    else
    {
        cout << "no data" << endl;
        return;
    }
}

int main()
{
    List lst;
    lst.display();

    cout << endl
         << "List push front:" << endl;

    lst.push_front(1);
    lst.push_front(3);
    lst.push_front(5);
    lst.display();

    cout << endl
         << "List push back:" << endl;

    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(5);
    lst.display();

    cout << endl
         << "List pop front:" << endl;

    lst.pop_front();
    lst.pop_front();
    lst.pop_front();
    lst.display();

    cout << endl
         << "List pop back:" << endl;

    lst.pop_back();
    lst.pop_back();
    lst.pop_back();
    lst.display();

    lst.push_front(111);
    lst.push_front(333);
    lst.push_front(555);

    lst.display();

    cout << endl
         << endl;
    cout << "find(x):" << endl;
    ;
    bool flag1 = lst.find(111);
    bool flag2 = lst.find(100);
    cout << "find(111)=" << flag1 << endl;
    cout << "find(100)=" << flag2 << endl;

    cout << endl
         << endl;
    cout << "insert():" << endl;
    lst.insert(10, 55555);
    lst.display();

    cout << endl
         << endl;
    lst.insert(2, 55555);
    lst.display();

    cout << endl
         << endl;
    cout << "erease(data):" << endl;

    cout << "ereasr(50):" << endl;
    lst.erease(50);
    lst.display();
    cout << "erease(555):" << endl;
    lst.erease(555);
    lst.display();

    return 0;
}