class Solution {
public:
    int findComplement(int num) {
        int a = num, count = 0;
        while (a > 0) {
            a = a >> 1;
            count++;
        }
        return pow(2,count)-1-num;
    }
};