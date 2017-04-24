/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 17-04-03 08:58
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long num = 0;
        while (n > 0) {
            num += n/5;
            n = n/5;
        }
        return num;
    }
};
