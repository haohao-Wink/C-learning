#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
using std ::cout;
using std ::endl;

// 类的声明
class Computer
{
public:
    void setBrand(const char *name);
    void setPrice(float price);
    void print();

private:
    char _name[20];
    float _price;
};

#endif