## new/delete表达式

在c中用来开辟和回收堆空间的方式：malloc/free
在C++中开辟和回收堆空间的方式：new/free

### 1.开辟一个元素的空间
```
int *p=new int(1);
cout<<*p<<endl;
delete p
```

### 2.开辟一个数组空间
```
//开辟数组时
int *p=new int[10]();

for(int idx=0;idx!=10;++idx){
        p[idx]=idx;
}

//回收
delete []p
```

#### new/delete表达式与malloc/free的区别？
>1.malloc/free是标准库函数；new/delete是C++的运算符或表达式

>2.new能够自动分配空间大小；malloc需要传入参数
            
>3.new开辟空间的同时还对空间进行初始化操作；malloc不行
                
>4.new/delete能对对象进行构造和析构函数的调用，进而对内存进行更加详细的工作；malloc/free不行

#### 既然new/delete的功能完全覆盖了，为什么还要保留malloc/free？
>因为C++经常需要调用C函数，C程序只能使用malloc/free管理动态内存。
