## 对象的组织
有了自己定义的类，或者使用别人定义好的类创建对象，其机制和使用int等创建普通变量几乎完全一致

### const对象
1. 类对象可以声明为const对象
2. 能作用于const对象的成员函数：构造函数、析构函数、const成员函数
3. const对象只能被创建、撤销、只读访问，不允许改写

### 指向对象的指针
```
类名 *指针名[=初始化表达式]

示例：
Point pt(1,2);
Point *p1=nullptr;
Point *p2=&pt;
Point *p3=new Point(3,4);
Point *p4=new Point[5];

p3->print();
(*p3).print();
```

### 对象数组
#### 声明
` 类名 数组名[对象个数]`

#### 初始化
```
    Point pt[5] = {Point(1, 2), Point(3, 4), Point(5, 6)};
//or
    Point pt[5] = {{1, 2}, {3, 4}, {5, 6}};
```

### 堆对象
通过new和delete表达式为对象分配动态存储区
```
void test()
{
    Point *pt = new Point(1, 2); // 堆对象
    pt->print();
    delete pt;
    pt = nullptr;

    cout << endl
         << endl;
    Point *pArray = new Point[10]();
    pArray[0] = {1, 2};

    // 固定数组删除格式
    delete[] pArray; // new,delete应该成对出现
    pArray = nullptr;
}

```