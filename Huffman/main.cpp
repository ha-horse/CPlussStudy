#include "huffman.h"

void main() {
    Huffman huf;
    huf.Init();

    int n =0;
    huf.Encode(n);
    huf.Decode(n);
}
