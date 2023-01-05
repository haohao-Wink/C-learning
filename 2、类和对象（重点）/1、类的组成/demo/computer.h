#ifndef __COMPUTER

#include <iostream>
using std ::cout;
using std ::endl;

class Computer
{

public:
    // 不能使用内联函数
    void setBrand(const char *name);
    void setPrice(float price);
    void print();

private:
    char _name[20];
    float _price;
};

#endif