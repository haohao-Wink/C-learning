## 迭代器
### 本质
lterator类的访问方式就是把不同集合类的访问逻辑抽象出来，使得不用暴露集合内部的结构而达到循环遍历结合的效果

### 迭代器类型
1. 随机访问迭代器 vector deque
2. 双向迭代器 list set multiset map multimap 
3. 前向迭代器 unordered_set unordered_multiset unordered_map unordered_multimap
4. 输出迭代器
5. 输入迭代器

### 流迭代器
可以将输入输出流作为容器看待

### 迭代器适配器
1. back_inserter函数模板，返回类型是back_insert_iterator
2. back_insert_iterator是类模板，底层调用push_back函数

3. front_inserter函数模板，返回类型是front_insert_iterator
4. front_insert_iterator是类模板，底层调用了push_front函数

5. inserter函数模板，返回类型是insert_iterator
6. insert_iterator是类模板，底层调用了insert函数

### 逆向迭代器