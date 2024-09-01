#include "huffman.h"

void Huffman::Init() {
    int num[256] = {0};
    int a[256]; // 字符权重数组，用于创建Huffman树的参数
    char b[256]; // 对应字符权重数组的字符,用于创建Huffman编码的参数
    len = 0; // 叶子结点数

    std::ifstream in("source.txt");
    char ch = in.get();
    while (!in.eof())
    {
        num[(int)ch]++;
        ch = in.get();
    }
    in.close();

    for (int i = 0; i < 256; i++)
    {
        if(num[i]>0) {
            a[len] = num[i];
            b[len] = (char)i;
            len++;
        }
    }
    CreateHTree(a);
    CreateCodeTable(b);
}

void Huffman::CreateHTree(int a[]) {
    HTree = new HNode [2 * len - 1];
    for (int i = 0; i < len; i++)
    {
        HTree[i].weight = a[i];
        HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;
    }
    int x, y;
    // 开始创建Huffman数
    for (int i = len; i < 2 * len - 1; i++)
    {
        // 从0~i中选出两个权值最小的结点
        SelectMin(x, y, 0, i);

        HTree[x].parent = HTree[y].parent = i;
        HTree[i].weight = HTree[x].weight + HTree[y].weight;
        HTree[i].LChild = x;
        HTree[i].RChild = y;
        HTree[i].parent = -1;
    }
    
}

void Huffman::CreateCodeTable(char b[]) {
    // 生成编码表
    HCodeTable = new HCode[len];

    for (int i = 0; i < len; i++)
    {
        HCodeTable[i].data = b[i];
        int child = i;
        int parent = HTree[i].parent;
        int k = 0;
        while (parent != -1)
        {
            if (child == HTree[parent].LChild)
            {
                HCodeTable[i].code[k] = '0';
            }
            else
            HCodeTable[i].code[k] = '1';
            k++;
            child = parent;
            parent = HTree[child].parent;
        }
        HCodeTable[i].code[k] = '\0';
        // 将编码字符逆置
        Reverse(HCodeTable[i].code);
    }
}

void Huffman::Encode(int &n) {
    unsigned char ch = 0x0; // 预留的空字节
    int bitlen = 0;
    n = 0;

    std::ifstream in("source.txt");
    std::ofstream out("encode.huf", std::ios::binary);

    char c = in.get();
    while (! in.eof())
    {
        // 在编码表中查找对应的字符
        char *sCode = FindCharCode(c);
        while (*sCode != '\0')
        {
            if (* sCode == '1') ch = ch | 0x1;
            else ch = ch | 0x0;

            bitlen++;
            if (bitlen == 8)
            {
                out.put(ch);
                bitlen = 0;
                ch = 0x0;
                n += 8;
            }
            ch = ch << 1;
            sCode++;         
        }
        c = in.get();
    }
    // 最后一个字符的编码不足8 bit 的处理
    if (bitlen > 0)
    {
        ch = ch << (7 - bitlen);
        out.put(ch);
        n += bitlen;
    }
    in.close();
    out.close();
}

void Huffman::Decode(int n) {
    int i = 0;
    std::ifstream in("encode.huf", std::ios::binary);
    std::ofstream out("decode.txt");
    unsigned char ch = in.get();
    while (!in.eof() && n > 0)
    {
        int parent = 2 * len -2;
        while (HTree[parent].LChild != -1)
        {
            if ((ch & 0x80) == 0) parent = HTree[parent].LChild;
            else parent = HTree[parent].RChild;
            ch = ch << 1;
            i++;
            n--;
            if (i == 8)
            {
                ch = in.get();
                i = 0;
            }
        }
        out.put(HCodeTable[parent].data);
    }
    in.close();
    out.close();
}

void Huffman::SelectMin(int &x, int &y, int s, int e) {
    int i;
    for (i = s; i <= e; i++)
    {
        if (HTree[i].parent == -1)
        {
            // 找出第一个有效权值x，并令 y = x
            x = y = i;
            break;
        }
        
    }
    
}

void Huffman::Reverse(char* s) {
    char *t = s;
    while (*t != '\0') t++;
    t--;
    // 交换首尾字符
    while (s < t)
    {
        char ch = * s;
        *s = *t;
        *t = ch;
        s++;
        t--;
    }
}

char* Huffman::FindCharCode(char ch) {
    for (int i = 0; i < len; i++)
    {
        if (HCodeTable[i].data == ch) return HCodeTable[i].code;
    }
    return NULL;
}

Huffman::~Huffman(){
    delete []HTree;
    delete []HCodeTable;
}
