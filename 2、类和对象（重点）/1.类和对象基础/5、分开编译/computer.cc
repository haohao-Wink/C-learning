#include "computer.h"
#include <string.h>

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
