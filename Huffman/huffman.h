#include <fstream>

struct HNode{
    int weight; // 结点权值
    int parent; // 双亲指针
    int LChild; // 左孩子指针
    int RChild; // 右孩子指针
};

struct HCode{
    char data;
    char code[100];
};


class Huffman {
private:
    HNode *HTree; // Huffman树
    HCode *HCodeTable; // Huffman编码表
    int len; // 叶子结点数

    // 在所有字符权重数组中选择 2 个最小的并且未使用过的字符进行建树
    void SelectMin(int &x, int &y, int s, int e);
    // 编码字符串的逆置
    void Reverse(char* s);
    char* FindCharCode(char ch);

public:
    // 读取文件生成权重表a[]
    void Init();
    // 创建huffman树
    void CreateHTree(int a[]);
    // 创建编码表
    void CreateCodeTable(char b[]);
    // 编码
    void Encode(int &n);
    // 解码
    void Decode(int n);
};
