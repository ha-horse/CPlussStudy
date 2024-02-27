class LinearList{
private:
    /* data */
    int *buffer;
    int size;
public:
    LinearList(int num);
    ~LinearList();

    //在线性表第i个元素后插入新元素x
    bool insert(int x, int i);
    //删除线性表的第i个元素
    bool remove(int &x, int i);
    //返回线性表的第i个元素
    int element(int i) const;
    //查找值为x的元素并返回其位置序号
    int search(int x) const;
    //返回线性表的长度
    int length() const;
};

// -------------------------------------------------------------------------
// queue
// ------------------------------------------------------------------------- 
//Queue是LinearList的派生类
class Queue:private LinearList{
private:
    /* data */
public:
    //元素x入队
    bool enQueue(int x);
    //元素出队
    bool deQueue(int &x);
};

// -------------------------------------------------------------------------
// stack
// ------------------------------------------------------------------------- 
//Stack是LinearList的派生类
class Stack:private LinearList{
public:
    //元素x入栈
    bool push(int x);
    //元素x出栈
    bool pop(int &x);
};

