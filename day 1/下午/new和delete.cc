#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

/*
malloc��free
new��delete
             ��ͬ�㣺
                ������������ѿռ�
                ����Ҫ�ɶԳ��֣����������ڴ�й©��

                �ڴ�й©�����ڴ桢�ڴ��̤
                macclo�ײ�ʵ��

            ��ͬ�㣺
                malloc/free����c�����еĿ⺯����new/delete����c++�еı��ʽ
                malloc����Ķѿռ���ԭʼ��δ��ʼ���ģ�new��������Ѿ���ʼ����
*/

// ����������ͷŶѿռ�

void test()
{
    int *p1 = (int *)malloc(sizeof(int)); // ����ѿռ䣨ԭʼ��δ��ʼ���Ķѿռ䣩
    memset(p1, 0, sizeof(int));           // ��ʼ��
    *p1 = 100;                            // ��ֵ
    free(p1);                             // �ͷŶѿռ�
    int *pArray = (int *)malloc(sizeof(int) * 10);
    memset(pArray, 0, sizeof(int) * 10);
    pArray[0] = 10;
    pArray[1] = 20;
}

void test1()
{
    int *pInt = new int(10);
    //*PInt =10;

    delete pInt; // �ͷŶѿռ�

    int *pArray = new int[10](); //"()��ʾ��ʼ��"
    pArray[0] = 10;
    pArray[1] = 20;
    delete[] pArray; // �ͷŶѿռ�����
}

int main()
{
    test();
    return 0;
}