## inline函数
>在C语言中，我们使用带参数的宏定义来借助编译器优化技术减少程序的执行时间
>在C++中，使用内联(inline)函数

### 1.什么是内联函数？
内联函数是C++的增强特性之一，用来降低程序的运行时间。当内联函数收到编译器的指示时，即可发生内联
> 编译器将使用函数的定义体来替代函数调用语句，这种替代行为发生在编译阶段而非程序运行阶段
>定义函数时，在函数的最前面以关键字"inline"声明函数，即可使函数称为内联声明函数
```
inline int max(int x,int y){
        return x>y?x:y;
}
```

### 2.内联函数和带参数的宏定义
#### 宏代码的缺点
>1.容易出错。预处理器在拷贝宏代码时，可能产生意想不到的边际效用

>2.不可调试。
>>内联函数可以调试。程序的调试版本中并没有真正的内联，编译器像普通函数一样生成含有调试信息的可执行代码。

>3.无法操作类的私有数据成员

#### 内联函数的优点
> 1.既具备宏代码的效率，又增加了安全性，而且可以自由操作类的数据成员。

> 2.函数被内联之后，编译器可以通过上下文相关的优化技术对结果代码执行更深入的优化。

### 3.将内联函数放入头文件
关键字inline必须与函数定义体放在一起才能使函数成为内联，仅将inline放在函数声明前不起任何作用。
所以说，inline函数是一种“用于实现的关键字”，而不是“用于声明的关键字”。

**内联函数应该在头文件中定义，编译器在调用点内联展开函数的代码时，必须能够找到inline函数的定义才能将调用函数替换为函数代码。**

### 4.谨慎使用内联
>内联函数以代码膨胀（拷贝）为代价，仅仅省去了函数调用的开销，从而提高程序的执行效率。

以下情况不宜使用内联：
> 1.如果函数体的代码比较长，使用内联将导致可执行代码膨胀过大

> 2.如果函数体内出现循环或其他复杂的控制结构，执行函数体内代码的时间将比函数调用的开销大得多

