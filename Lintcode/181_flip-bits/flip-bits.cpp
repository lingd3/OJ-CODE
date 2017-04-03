/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 17-04-03 09:19
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c = a^b;
        int count = 0;
        while (c) {
            c = c & (c-1);
            ++count;
        }
        return count;
    }
};