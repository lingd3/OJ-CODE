class Solution {
public:
    int climbStairs(int n) {    //找到规律，即斐波那契数列
        if (n <= 2) return n;
        else {
            int a[n] = {1, 2};
            for (int i = 3; i <= n; i++) {
                a[i-1] = a[i-2] + a[i-3];
            }
            return a[n-1];
        }
    }
};