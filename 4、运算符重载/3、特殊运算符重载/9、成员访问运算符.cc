#include <iostream>

using std ::cout;
using std::endl;

class Data
{
public:
    Data(int data = 0)
        : _data(data)
    {
        cout << "Data(int =0)" << endl;
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

    Data &operator*()
    {
        return *_pdata;
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

void test()
{
    // 智能指针的雏形
    SecondLayer sl(new Data(10)); // 栈对象
    cout << "s1->getData()=" << sl->getData() << endl;
    // sl -> getData() ====> sl.operator -> ()->getData()
    cout << "(*sl).getData()=" << (*sl).getData() << endl;
    // (*sl).getData() ====>sl.operator*().getData()

    cout << endl
         << endl;
    ThirdLayer tl1(new SecondLayer(new Data(30))); // 栈对象
    cout << "tl1->getData()=" << tl1->getData() << endl;
    // tl1->getData() ====>tl1.operator->().operator->()->getData() << endl;
}

int main()
{
    test();
    return 0;
}