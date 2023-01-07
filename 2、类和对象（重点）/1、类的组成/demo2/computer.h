#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <iostream>
using std ::cout;
using std ::endl;

// 类的声明
class Computer
{
public:
    Computer(const char *name, float price);

    Computer(const Computer &rhs);

    void setBrand(const char *name);
    void setPrice(float price);
    void print();

    ~Computer();

private:
    char *_name;
    float _price;
};

#endif