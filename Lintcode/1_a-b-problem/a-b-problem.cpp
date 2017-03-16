/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: C++
@Datetime: 17-03-14 03:58
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int sum, carry;
        do {
            sum = a^b;
            carry = (a&b) << 1;
            a = sum;
            b = carry;
        } while (b != 0);
        return a;
    }
};