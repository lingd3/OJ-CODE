/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 17-04-03 09:05
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        int a[10] = {0};
        while (n) {
            a[n%10]++;
            n /= 10;
        }
        int num = 0, count = 0;
        for (int i = 0; i < 10; i++) {
            num += i*i*a[i];
            a[i] = 0;
        }
        while (num != 1) {
            while (num) {
                a[num%10]++;
                num /= 10;
            }
            for (int i = 0; i < 10; i++) {
                num += i*i*a[i];
                a[i] = 0;
            }
            count++;
            if (count > 10000) return false;
        }
        return true;
    }
};