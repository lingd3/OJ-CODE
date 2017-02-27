/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 17-02-26 11:31
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> v;
        if (n <= 0) return v;
        char *num = new char[n+1];
        num[n] = '\0';
        for (int i = 0; i < 10; i++) {
            num[0] = i+'0';
            recursion(num, n, 0, v);
        }
        delete []num;
        return v;
    }
    
    void recursion(char *num, int length, int index, vector<int>&v) {
        if (index == length-1) {
            int a = atoi(num);
            if (a != 0) {
                v.push_back(a);
            }
            return;
        } 
        for (int i=0; i< 10; i++) {  
            num[index + 1] = i +'0';  
            recursion(num,length, index+1 ,v);  
              
        }  
        return;
    }
    
};



