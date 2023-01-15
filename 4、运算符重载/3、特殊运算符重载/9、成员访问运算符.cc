#include <iostream>

using std ::cout;
using std::endl;

class Data
{
public:
    Data(int data = 0)
        : _data(data)
    {
        cout << "Data(int =0" << endl;
    }

    int getData() const
    {
        return _data;
    }

    ~Data()
    {
        cout << "~Data()" << endl;
    }

private:
    int _data;
};

class SecondLayer
{
public:
    SecondLayer(Data *pdata)
        : _pdata(pdata)
    {
        cout << "SecondLayer(Data *)" << endl;
    }

    ~SecondLayer()
    {
        cout << "~SecondLayer()" << endl;
        if (_pdata)
        {
            delete _pdata;
            _pdata = nullptr;
        }
    }

    // 重载 ->运算符
    Data *operator->()
    {
        return _pdata;
    }

private:
    Data *_pdata;
};

class ThirdLayer
{
public:
    ThirdLayer(SecondLayer *psl)
        : _psl(psl)
    {
        cout << "thirdLayer(SecondLayer *)" << endl;
    }

    ~ThirdLayer()
    {
        cout << "~ThirdLayer()" << endl;
        if (_psl)
        {
            delete _psl;
            _psl = nullptr;
        }
    }

    SecondLayer &operator->()
    {
        return *_psl;
    }

private:
    SecondLayer *_psl;
};