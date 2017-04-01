/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/add-digits
@Language: C++
@Datetime: 17-04-01 12:53
*/

class Solution {
public:
    /**
     * @param num a non-negative integer
     * @return one digit
     */
    int addDigits(int num) {
        // Write your code here
        return (num - 1) % 9 + 1;
    }
    
};