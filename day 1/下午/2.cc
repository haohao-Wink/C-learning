#include <iostream>

using std ::cout;
using std ::endl;

void test()
{
    int a;
    a = 20;

    cout << "hello world" << endl;
}

void test2()
{
    int value = 100;
    int *p1 = &value; // ��ʼ��

    *p1 = 200; // �޸�ָ����ָ������
    p1 = NULL; // ָ���ָ��

    cout << *p1 << endl;

    cout << endl
         << endl;
    int value1 = 3;
    const int *p2 = &value1;
    //*p2 = 22;    // error�����ܸı�ָ����ָ������
    p2 = &value; // ���Ըı�ָ���ָ��

    int value3 = 300;
    int const &p3 = &value3;
    *p3 = 22;
    p3 = &value; // ��ֵ
}

int main()
{
    test2();
    return 0;
}

// constλ��*�ұߣ���Ϊָ�볣��
//*p4=22;//���Ըı�ָ����ָ����
//*p4=&value//�����Ըı�ָ��ָ��

/*
    ��constλ��*��ߣ���Ϊ����ָ��

*/

// ��ʼ������ǰ������
// ��ֵǰ����������

/*
����ָ���ָ�뺯����

    ����ָ�룺int (*pFunc)(int x);
            ָ��ָ����
    ָ�뺯����int *func(int x);
            ָ��ָ�룬��������Ϊ int*

����ָ���ָ������

    ����ָ�룺  int ��*pArry)[]
            �����д洢ָ��
    ָ������:   int *pArry[]

*/

// const * const
// �Ȳ����Ըı�ָ����ָ����Ҳ�����Ըı�ָ��ָ��