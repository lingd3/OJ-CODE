/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 17-02-26 12:04
*/

class Solution {  //(a * b) % p = (a % p * b % p) % p
public:           //a^n %p = (a^1/2 %p ) × ( a^1/2 %p) %p
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if (n == 0) return 1%b;
        if (n == 1) return a%b;
        if (n < 0) return -1;
        long result = fastPower(a, b, n/2);
        result = (result*result)%b;
        if (n%2 == 1) result = (result*(a%b))%b;
        return (int)(result);
    }
};