#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test()
{

    cout << "sizeof(string)=" << sizeof(string) << endl
         << endl;

    int a = 10; // 栈对象

    int *pInt = new int(100); // 堆对象

    string s1 = "hello";
    string s2 = "helloworldwuhan";
    string s3 = "welcomec++,helloworldwuhan";

    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    cout << "s3=" << s3 << endl;

    cout << endl
         << endl;
    printf("s1'address=%p\n", s1.c_str());
    printf("s2'address=%p\n", s2.c_str());
    printf("s3'address=%p\n", s3.c_str());

    printf("&a=%p\n", &a);
    printf("pInt=%p\n", pInt);
    printf("&pInt=%p\n", &pInt);

    delete pInt;
    pInt = nullptr;
}

int main()
{
    test();
    return 0;
}