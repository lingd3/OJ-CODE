/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 17-04-03 09:24
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    
    bool isPrime(int n) {
        if (n == 2 || n == 3) return true;
        for (int i = 2; i < n/2+1; i++) {
            if (n%i == 0) return false;
        }
        return true;
    }
     
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1 || num == 2) return true;
        for (int i = 2; i < num/2+1; i++) {
            if (num%i == 0 && i != 2 && i != 3 && i != 5 && isPrime(i)) return false;
        }
        return true;
    }
};