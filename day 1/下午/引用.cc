#include <iostream>
#include <string.h>

using std ::cout;
using std ::endl;

// ָ�������õ�����

void test()
{
    // ������һ�������ı����������ڶ����ʱ������ʼ��
    // �����ص㣺���������Ŀ����Ϊ�˼���ָ���ʹ��
    int number = 10;
    int &ref = number;
    cout << "number=" << number << endl;
    cout << "number" << ref << endl;
    printf("&number=%p\n", &number);
    printf("&ref=%p\n", &ref);

    cout << endl;

    // �������úͲ���ʵ�屾������ͬ
    int num2 = 200;
    // �������ڳ�Ϊnum2�ı���
    ref = num2;
    cout << "number=" << number << endl;
    cout << "number" << ref << endl;
    cout << "num2=" << num2 << endl;

    // ���õı��ʾ���ָ�룬���ܸı�ָ�򡣵���һ��ָ�볣����* const��
    // �����ڶ����ʱ�������г�ʼ�������ܵ������ڣ�����ᱨ��
    // �ڳ�ʼ����ʱ�򣬱���󶨵������ϣ�һ���󶨣�����ı�ָ��
    // int &ref2;//error
}

void test1()
{
}

// ֵ���ݣ�����
// �����Ƚϴ�

// ָ�봫��
// ֱ���Բ���
void swap(int *px, int *py) // int x=a,int y=4;
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

//     ������Ϊ�����ķ�������
void test2()
{
    int a = 3, b = 4;
    cout << "����֮ǰa=" << a << ",b=" << b << endl;
    swap(&a, &b);
    cout << "����֮ǰa=" << a << ",b=" << b << endl;
}

int main()
{
    test2();
    return 0;
}

// ָ��
//     ������Ϊ�����Ĳ���

#if 0
void swap(int x, int y) // int x=a,int y=4;
{
    int tmp = x;
    x = y;
    y = tmp;
}
#endif

// ���ô���
// ����ʵ�������������һ����Ч��
int &func()
{
    int number = 10;
    return number;
}

// ��Ҫ���ؾֲ���������

int arr[5] = {1, 2, 3, 4, 5};
int &getIndex(int idx)
{
    return arr[idx];
}

// �����ķ��ؽ��ʹ�����õ�ǰ�᣺ʵ����������ڴ��ں�������������

int &getHeapData()
{
    int *pInt = new int(200);
    return *pInt;
}

// ������Ҫʹ�öѿռ䣬���ܷ����ڴ�й©���⣬���һ��Ҫ���ضѿռ�����ã���Ҫ�Զ�����ڴ��ͷ�