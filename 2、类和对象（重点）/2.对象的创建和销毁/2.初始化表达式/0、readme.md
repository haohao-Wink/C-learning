## 初始化表达式

1. 构造函数对数据成员进行初始化时，可以通过初始化列表完成
2. 初始化列表位于构造函数形参列表之后，在函数体之前，用冒号开始
3. 如果有多个数据成员，使用逗号分隔，初值放在一对小括号中

如果没有在构造函数的初始化列表中显示的初始化成员，则改成员将在构造函数体之前执行默认初始化

**每个成员在初始化列表中只能出现一次，其初始化顺序不是由成员变量在初始化列表中的顺序决定，而是由成员变量在类中被声明的顺序决定**