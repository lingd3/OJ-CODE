/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 16-08-02 12:33
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n < 4) return n;
        int a[100] = {1, 2, 3};
        for (int i = 3; i < n; i++) {
            a[i] = a[i-1] + a[i-2];
        }
        return a[n-1];
    }
};
