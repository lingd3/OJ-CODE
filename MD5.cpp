#include <iostream>
#include <string>
using namespace std;
unsigned int extendLength;
unsigned int* extendString;
unsigned int A, B, C, D;

//四个基本的非线性函数
//
unsigned int F(unsigned int x, unsigned int y, unsigned int z) {
    return (x&y) | ((~x)&z);
}
unsigned int G(unsigned int x, unsigned int y, unsigned int z) {
    return (x&z) | (y&(~z));
}
unsigned int H(unsigned int x, unsigned int y, unsigned int z) {
    return x^y^z;
}
unsigned int I(unsigned int x, unsigned int y, unsigned int z) {
    return y^(x|(~z));
}

//循环左移
unsigned int shiftLeft(unsigned int x, int n) {
    return (x << n) | (x >> (32-n));
}

//四个循环函数
void FF(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int k) {
    a = shiftLeft(a+F(b,c,d)+x+k, s) + b;
}
void GG(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int k) {
    a = shiftLeft(a+G(b,c,d)+x+k, s) + b;
}
void HH(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int k) {
    a = shiftLeft(a+H(b,c,d)+x+k, s) + b;
}
void II(unsigned int &a, unsigned int b, unsigned int c, unsigned int d, unsigned int x, unsigned int s, unsigned int k) {
    a = shiftLeft(a+I(b,c,d)+x+k, s) + b;
}

//填充
unsigned int* extend(string s) {
    unsigned int groupNum = ((s.size()+8)*8)/512+1;
    extendLength = groupNum*16;
    extendString = new unsigned int[extendLength];
    for (unsigned int i = 0; i < extendLength; i++) extendString[i] = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        extendString[i>>2] |= (s[i])<<((i%4)*8);
    }
    extendString[s.size()/4] |= 0x80<<(((s.size()%4))*8);
    extendString[extendLength-2] = s.size()*8;
    
    return extendString;
}

//处理分组数据
void transform(unsigned int n[]) {
    unsigned int a = A, b = B, c = C, d = D;
    
    //第一轮
    FF (a, b, c, d, n[0], 7, 0xd76aa478);
    FF (d, a, b, c, n[1], 12, 0xe8c7b756);
    FF (c, d, a, b, n[2], 17, 0x242070db);
    FF (b, c, d, a, n[3], 22, 0xc1bdceee);
    FF (a, b, c, d, n[4], 7, 0xf57c0faf);
    FF (d, a, b, c, n[5], 12, 0x4787c62a);
    FF (c, d, a, b, n[6], 17, 0xa8304613);
    FF (b, c, d, a, n[7], 22, 0xfd469501);
    FF (a, b, c, d, n[8], 7, 0x698098d8);
    FF (d, a, b, c, n[9], 12, 0x8b44f7af);
    FF (c, d, a, b, n[10], 17, 0xffff5bb1);
    FF (b, c, d, a, n[11], 22, 0x895cd7be);
    FF (a, b, c, d, n[12], 7, 0x6b901122);
    FF (d, a, b, c, n[13], 12, 0xfd987193);
    FF (c, d, a, b, n[14], 17, 0xa679438e);
    FF (b, c, d, a, n[15], 22, 0x49b40821);
    
    //第二轮
    GG (a, b, c, d, n[1], 5, 0xf61e2562);
    GG (d, a, b, c, n[6], 9, 0xc040b340);
    GG (c, d, a, b, n[11], 14, 0x265e5a51);
    GG (b, c, d, a, n[0], 20, 0xe9b6c7aa);
    GG (a, b, c, d, n[5], 5, 0xd62f105d);
    GG (d, a, b, c, n[10], 9,  0x2441453);
    GG (c, d, a, b, n[15], 14, 0xd8a1e681);
    GG (b, c, d, a, n[4], 20, 0xe7d3fbc8);
    GG (a, b, c, d, n[9], 5, 0x21e1cde6);
    GG (d, a, b, c, n[14], 9, 0xc33707d6);
    GG (c, d, a, b, n[3], 14, 0xf4d50d87);
    GG (b, c, d, a, n[8], 20, 0x455a14ed);
    GG (a, b, c, d, n[13], 5, 0xa9e3e905);
    GG (d, a, b, c, n[2], 9, 0xfcefa3f8);
    GG (c, d, a, b, n[7], 14, 0x676f02d9);
    GG (b, c, d, a, n[12], 20, 0x8d2a4c8a);
    
    //第三轮
    HH (a, b, c, d, n[5], 4, 0xfffa3942);
    HH (d, a, b, c, n[8], 11, 0x8771f681);
    HH (c, d, a, b, n[11], 16, 0x6d9d6122);
    HH (b, c, d, a, n[14], 23, 0xfde5380c);
    HH (a, b, c, d, n[1], 4, 0xa4beea44);
    HH (d, a, b, c, n[4], 11, 0x4bdecfa9);
    HH (c, d, a, b, n[7], 16, 0xf6bb4b60);
    HH (b, c, d, a, n[10], 23, 0xbebfbc70);
    HH (a, b, c, d, n[13], 4, 0x289b7ec6);
    HH (d, a, b, c, n[0], 11, 0xeaa127fa);
    HH (c, d, a, b, n[3], 16, 0xd4ef3085);
    HH (b, c, d, a, n[6], 23,  0x4881d05);
    HH (a, b, c, d, n[9], 4, 0xd9d4d039);
    HH (d, a, b, c, n[12], 11, 0xe6db99e5);
    HH (c, d, a, b, n[15], 16, 0x1fa27cf8);
    HH (b, c, d, a, n[2], 23, 0xc4ac5665);
    
    //第四轮
    II (a, b, c, d, n[0], 6, 0xf4292244);
    II (d, a, b, c, n[7], 10, 0x432aff97);
    II (c, d, a, b, n[14], 15, 0xab9423a7);
    II (b, c, d, a, n[5], 21, 0xfc93a039);
    II (a, b, c, d, n[12], 6, 0x655b59c3);
    II (d, a, b, c, n[3], 10, 0x8f0ccc92);
    II (c, d, a, b, n[10], 15, 0xffeff47d);
    II (b, c, d, a, n[1], 21, 0x85845dd1);
    II (a, b, c, d, n[8], 6, 0x6fa87e4f);
    II (d, a, b, c, n[15], 10, 0xfe2ce6e0);
    II (c, d, a, b, n[6], 15, 0xa3014314);
    II (b, c, d, a, n[13], 21, 0x4e0811a1);
    II (a, b, c, d, n[4], 6, 0xf7537e82);
    II (d, a, b, c, n[11], 10, 0xbd3af235);
    II (c, d, a, b, n[2], 15, 0x2ad7d2bb);
    II (b, c, d, a, n[9], 21, 0xeb86d391);
    
    A = a+A;
    B = b+B;
    C = c+C;
    D = d+D;
}

string changeHex(int a) {
    int b;
    string str1;
    string str = "";
    char str16[] = "0123456789abcdef";
    for(int i = 0; i < 4; i++) {
        str1 = "";
        b = ((a>>i*8)%(1<<8))&0xff;   //逆序处理每个字节
        for (int j = 0; j < 2; j++) {
            str1.insert(0, 1, str16[b%16]);
            b = b/16;
        }
        str += str1;
    }
    return str;
}

//MD5加密
string MD5(string s) {
    //1.填充
    unsigned int *newStr = extend(s);

    //2.初始化变量
    A = 0x67452301;
    B = 0xefcdab89;
    C = 0x98badcfe;
    D = 0x10325476;
    
    //3.处理分组数据
    for (unsigned int i = 0; i < extendLength/16; i++) {
        unsigned int num[16];
        for (unsigned int j = 0; j < 16; j++) {
            num[j] = newStr[i*16+j];
        }
        transform(num);
    }
    
    //4.输出
    return changeHex(A)+changeHex(B)+changeHex(C)+changeHex(D);
}

int main() {
    cout << "几个常见的字符串经过MD5加密的结果如下：" << endl;
    cout << "\"\"      加密后为：" << MD5("") << endl;
    cout << "\"a\"     加密后为：" << MD5("a") << endl;
    cout << "\"abc\"   加密后为：" << MD5("abc") << endl;
    while (true) {
        cout << "请输入要加密的字符串：";
        string s;
        getline(cin, s);
        cout << MD5(s) << endl;
    }
    return 0;
}