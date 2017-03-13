/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 17-03-13 08:58
*/

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int min(int a, int b, int c) {
        int m = a;
        if (b < m) m = b;
        if (c < m) m = c;
        return m;
    }
    
    int nthUglyNumber(int n) {
        // write your code here
        int a[n], max = 1;
        a[0] = 1;
        for (int i = 0; i < n; i++) {
            int max2, max3, max5;
            for (int j = 0; j <= i; j++) {
                if (a[j]*2 > max) {
                    max2 = a[j]*2;
                    break;
                }
            }
            for (int j = 0; j <= i; j++) {
                if (a[j]*3 > max) {
                    max3 = a[j]*3;
                    break;
                }
            }
            for (int j = 0; j <= i; j++) {
                if (a[j]*5 > max) {
                    max5 = a[j]*5;
                    break;
                }
            }
            max = min(max2, max3, max5);
            a[i+1] = max;
        }
        return a[n-1];
    }
};






