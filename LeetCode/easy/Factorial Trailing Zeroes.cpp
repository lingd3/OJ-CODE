class Solution {
public:
	//因为阶乘末尾的0都是2*5得到的，而除0，1外的数的阶乘的因子2的数量总是多于5的数量，所以
	//只需要统计因子5的数量
    int trailingZeroes(int n) {
       int count = 0;
       while (n) {
           n /= 5;
           count += n;
       }
       return count;
    }
};