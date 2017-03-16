/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: Java
@Datetime: 17-03-14 05:52
*/

public class Solution {
    /**
     * @param str: A string
     * @return An integer
     */
    public int atoi(String str) {
        // write your code here
        if (str == null || str.length() == 0) return 0;
        str = str.trim();
        char flag = '+';
        int i = 0;
        if (str.charAt(0) == '+') {
            i++;
        }
        if (str.charAt(0) == '-') {
            i++;
            flag = '-';
        }
        double res = 0;
        while (i < str.length() && str.charAt(i) <= '9' && str.charAt(i) >= '0') {
           res = res * 10 + str.charAt(i) - '0'; 
           i++;
        }
        if (flag == '-') {
            res = -1 * res;
        }
        if (res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (res < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        return (int)res;
    }
}