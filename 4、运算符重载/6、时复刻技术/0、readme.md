## 标准库中string的底层实现方式

**每种实现都包含以下信息：**
1. 字符串的大小
2. 能够容纳的字符数量
3. 字符串内容本身

### 1.Eager copy（深拷贝）
如果只读，浅拷贝更好
```
class String{
    public:
    String (const String &rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
    }
    private:
    char *_pstr;
};
```

### 2.COW(copy-on-write)
1. 当两个std::string发生复制构造或者复制时，不会复制字符串内容，而是增加一个引用计数器，然后字符串指针进行浅拷贝
2. 只有当需要修改其中一个字符串内容时，才真正执行复制
3. 实现方式：浅拷贝+引用计数

### 3.SSO
1. 核心思想：发生拷贝时要复制一个指针

### 4.最佳策略
1. 短字符串用SSO
2. 中等长度字符串使用eager copy
3. 很长的字符串使用COW

### 5.线程安全性
CPU的原子操作虽然比mutex锁好多了，但是仍然会带来性能损失
1. 阻止了CPU的乱性执行
2. 两个CPU对同一个地址进行原子操作，会导致cache失效，从而重新从内存中读数据
3. 系统通常会lock住比目标地址更大的一片区域，影响逻辑上不相关的地址访问

### 额外

1. linux下查看版本号
`
lsb_release -a
`