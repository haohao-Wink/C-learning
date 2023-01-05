#include "computer.h"
#include <iostream>

using std::cout;
using std::endl;

// 类名和作用域限定符表示
void Computer::setBrand(const char *name)
{
    strcpy(_name, name);
}

void Computer::setPrice(float price)
{
    _price = price;
}
void Computer::print()
{
    cout << "name=" << _name << endl;
    cout << "price=" << _price << endl;
}
