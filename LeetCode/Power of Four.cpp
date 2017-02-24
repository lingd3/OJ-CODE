class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};
//法二：
return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
//法三：
return num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0;