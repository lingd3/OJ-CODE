/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 17-03-11 11:03
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        if (k == 0) count++;
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num) {
                if (num%10 == k) count++;
                num /= 10;
            }
        }
        return count;
    }
};