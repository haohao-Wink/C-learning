#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void test()
{
    int x, y;
    cin >> x >> y;

    try
    {
        if (0 == y)
        {
            throw y;
        }
        else
        {
            cout << "(x/y)=" << x / y << endl;
        }
    }

    catch (int e)
    {
        // 写异常处理逻辑
        cout << "catch(int)" << endl;
    }

    catch (double e)
    {
        cout << "catch(double)" << endl;
    }

    catch (long e)
    {
        cout << "catch(long)" << endl;
    }
}

int main()
{
    test();
    return 0;
}