/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 17-03-13 13:23
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> v;
        if (A.size() < 2) return v;
        int n = 0;
        for (int i = 0; i < A.size(); i++) {
            n ^= A[i];
        }
        unsigned int index = findTheIndex(n);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < A.size(); i++) {
            if (isBit1(A[i], index)) num1 ^= A[i];
            else num2 ^= A[i];
        }
        v.push_back(num1);
        v.push_back(num2);
        return v;
    }
    
    unsigned int findTheIndex(int num) {
        int count = 0;
        while ((num&1) == 0) {
            num = num >> 1;
            count++;
        }
        return count;
    }
    
    bool isBit1(int num, int index) {
        num = num >> index;
        return (num & 1);
    }
    
};