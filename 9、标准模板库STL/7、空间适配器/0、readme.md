## 空间适配器

### 头文件
```
template <class T> struct allocator;
template <> struct allocator <void>;
```

### 空间申请与释放以及对象的构建与销毁
```
//空间的申请，申请的为原始的，未初始化的空间
pointer allocate (size_type n,const void *hint=0);
T* allocate(std::size_t n,const void* hint);
T * allocate(std::size_t n);

//空间释放
void deallocate(T* p,std::size_t n);

//对象的构建，在指定的未初始化空间上构建对象，使用定位new表达式
void construct (pointer p,const_reference val);

//对象的销毁
void destroy (pointer p);
```

### 定位new表达式
1. 定位new表达式接受指向未构造内存的指针，并在该空间中初始化一个对象或者数组
2. 他只在特定的，预分配的内存地址构造一个对象

### 真正具备空间分配功能的std::alloc
1. 第一级空间适配器使用类模板`malloc_alloc_template`；底层使用malloc、free进行空间的申请与释放
2. 第二级空间适配器使用类模板`default_alloc_template`；底层根据申请空间大小分为两个分支，大于128B，使用第一级配置空间模板；小于使用内存池加16个自由链表

#### Q：为什么要分成两部分：
1. 向系统堆要空间
2. 考虑多续状态
3. 考虑内存不足的应变措施
4. 考虑过多小块内存造成的小碎片

#### 内存碎片
内部碎片：页式管理、段式管理、段页式管理（局部性原理），无法避免，但是可以通过算法优化
外部碎片：申请堆内存之间的片段空隙，合理使用

#### 分成两部分的解决方案
1. 一级空间适配器
使用malloc、free调用
缺点：频繁的用户态到核心态的切换，开销大

2. 二级空间适配器
内存池+16个自由链表
优点：空间换时间
缺点：内存占比较大，如果内存有限，内存不可控

#### 释放内存的deallocate
1. 一级空间适配器：直接使用free将内存收回到堆空间
2. 二级空间适配器 直接将用完后的空间链回到相应的链表下，使用头插法进行连接