class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n <= 1) return n;
        int count = 0, i;
        for (i = 0; ;i++) {
            if (pow(2,i) <= n && pow(2, i+1) > n) break;
        }
        while (i >= 0 && n != 0) {
            if (pow(2, i) <= n) {
                n = n-pow(2,i);
                count++;
            }
            i--;
        }
        return count;
    }
};
//聪明的做法
int hammingWeight(uint32_t n) {
    int res = 0;
    while(n)
    {
        n &= n - 1;
        ++ res;
    }
    return res;
}