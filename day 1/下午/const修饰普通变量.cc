#include <iostream>

using namespace std;
using std ::cout;
using std ::endl;

// �궨��
#define MAX 100

// �������ĺ궨��
#define multiply(x, y) x *y

void test()
{
    int a;
    a = 20;
    // ngcc���ע�Ͷ��У�u����
    /*
    ����const���εı�����Ϊ����
    �����ڶ����ʱ�򣬱����ʼ��
    */
    const int number = 10;
    // �������ܽ��и�ֵ

    /*
        �������ͣ�char/short/int/double/float/void *
    */
    cout << "hello world" << endl;
}

int main()
{
    test();
    return 0;
}

/*
    �궨�巢����Ԥ����׶Σ�����ֱ�ӣ����ַ����滻����
        ����궨�巢�����󣬱���������ʱ���ܷ���
    const�ڱ���ʱ����������д��󣬿����ڱ���ʱ����
*/
