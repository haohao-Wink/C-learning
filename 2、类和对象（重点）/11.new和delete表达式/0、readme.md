## new 与delete表达式
### 1.new表达式工作步骤
#### 步骤：
1. 调用名为operator new的标准库函数，分配足够大的原始未类型化的内存，以保存指定类型的一个对象
2. 运行该类型的一个构造函数初始化对象
3. 返回指向新分配并构造的构造函数对象的指针

### 2.delete表达式
#### 步骤：
1. 调用析构函数，回收对象中数据成员所申请的资源
2. 调用名为operator delete的标准库函数释放该对象所用内存

### 3.operator new和operator delete函数的重载版本
```
//operator new库函数
void *operator new(size_t);
void *operator new [](size_t);

//operator delete库函数
void operator delete (void *);
void operator delete[](void *);
```