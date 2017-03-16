/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 17-03-14 06:06
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        vector<long long> v;
        if (size == 0) return v;
        for (int i = 0; i < size; i++) {
            long long n = 1;
            for (int j = 0; j < size; j++) {
                if (j == i) continue;
                else n *= nums[j];
            }
            v.push_back(n);
        }
        return v;
    }
};