## C++解决方案 RAII技术

资源管理RAII技术，利用对象的生命周期管理程序资源，因为对象在离开作用域时，会自动调用析构函数
### 关键
保证资源的释放顺序和获取顺序相反
### RAII常见特征
1. 在构造时，初始化资源或者托管资源
2. 析构时释放资源
3. 一般不允许赋值或者复制
4. 提供若干访问资源的方法

### 区分
1. 值语义：可以进行赋值与复制
2. 对象语义：不能进行赋值与复制
