## 继承的定义
### 1. 形式
```
class 派生类
:public/protected/private 基类
{};
```

### 2. 派生类的生成过程
1. 吸收基类的成员
2. 改造基类的成员
3. 添加自己新的成员

### 3.继承的局限
以下基类的特征不能从基类继承：
1. 构造函数
2. 析构函数
3. 用户重载的operator new/delete运算符
4. 用户重载的operator=运算符
5. 友元 关系

