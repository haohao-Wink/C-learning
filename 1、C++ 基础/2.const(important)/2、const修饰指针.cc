#include <iostream>

using std ::cout;
using std ::endl;

/*
    ��constλ��*��ߵ�ʱ��ͳ��Ϊ����ָ�루pointer to const��
        ���ܸı�ָ�����ݣ����Ըı�ָ��ָ��

    ��constλ��*�ұ�ʱ��ͳ��Ϊָ�볣����const pointer��
        ���ܸı�ָ��ָ�򣬵��ǿ��Ըı�ָ������

    ����const����˭��˭�Ͳ����Ըı�

    const *const��
        �Ȳ����Ըı�ָ����ָ����Ҳ�����Ըı�ָ��ָ��

*/

/*
    ����ָ���ָ�뺯����

        ����ָ�룺int (*pFunc)(int x);
            ָ��ָ����
        ָ�뺯����int* func(int x);
            ָ��ָ�룬��������Ϊ int*

    ����ָ���ָ������

        ����ָ�룺  int ��*pArry)[]
            �����д洢ָ��
        ָ������:   int* pArry[]

*/

#if 0
    int *p=&value;//��ʼ��
    p=&value;//��ֵ

    ע��
        ��ʼ������ǰ�����ͣ���Ϊ��һ�γ���
        ��ֵǰ���������ͣ����ǵ�һ�γ���
#endif

void test2()
{
    int value = 100;
    int *p1 = &value;    // ��ʼ��
    *p1 = 200;           // �޸�ָ����ָ������
    cout << *p1 << endl; // ����ָ�� *p1 ������

    p1 = NULL; // ָ���ָ��

    cout << endl
         << endl;
    int value2 = 3;
    const int *p2 = &value2;
    //*p2 = 22;    //error�����ܸı�ָ����ָ������
    p2 = &value; // ok,���Ըı�ָ���ָ��

    cout << endl
         << endl;
    int value3 = 300;
    int const *p3 = &value3;
    //*p3 = 22;    // error�����ܸı�ָ����ָ������
    p3 = &value; // ok,���Ըı�ָ���ָ��

    cout << endl
         << endl;
    int value4 = 400;
    int *const p4 = &value4;
    *p4 = 22; // ok�����ܸı�ָ����ָ������
    // p4 = &value; // error,���Ըı�ָ���ָ��
}

int main()
{
    test2();
    return 0;
}

// const * const
// �Ȳ����Ըı�ָ����ָ����Ҳ�����Ըı�ָ��ָ��