#include <iostream>
using namespace std;

inline int max(int x, y)
{
    return x > y ? x : y;
}

int main()
{
    int x = 1, y = 2;
    cout << max(x, y) << endl;
    return 0;
}