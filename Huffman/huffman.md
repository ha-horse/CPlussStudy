Huffman编码树是一棵带权路径长度最短的二叉树。
Huffman 编码需要将待编码的数据扫描两遍。
第一遍：统计原数据中各字符出现的频率，利用得到的频率创建Huffman编码树，
并把树的信息保存起来，以便解压时创建同样的Huffman树进行解压。

第二遍：根据第一遍扫描得到的Huffman树进行编码，并把编码后得到的码字存储起来。

* 本例中待压缩的文件是文本文件 source.txt，使用输入文件流一个字符一个字符地读取该源文件的文本。比如source.txt文本内容为："ACCZBBBAAACBBZABAAAA"，每读出一个字符，只要在编码表中找出对应的编码即可。
* 由于文件的最小读取单位是字节，但压缩编码时每个字符的编码是以 bit 为单位，所以需要预置一个空字节，然后将字符的编码一个 bit 一个 bit 地从低位移至高位，直到满一个字节为止，再存入压缩后的二进制文件encode.huf。

---

源字符串:ACCZBBBAAACBBZABAAAA

压缩后:01011011 00111111 00010111 11100011 00000000