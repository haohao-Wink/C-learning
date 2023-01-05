class Test
{
public:
    // 数据成员的初始化与其在初始化列表中的顺序没有关系，与数据成员在声明中的顺序有关
    Test(int value)
        : _iy(value), _ix(_iy) {}

private:
    int _ix;
    int _iy;
};