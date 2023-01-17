class Line
{
public:
    Line(int, int, int, int);
    ~Line();

    void printLine() const;

private:
    class LineImpl; // 类的前向声明
    LineImpl *_pimpl;
};