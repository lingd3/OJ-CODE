/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 17-03-11 08:51
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int size = nums.size();
        if (size == 0) return 0;
        int curSum = 0;
        int bigSum = nums[0];
        for (int i = 0; i < size; i++) {
            if (curSum <= 0) curSum = nums[i];
            else curSum += nums[i];
            if (curSum > bigSum) bigSum = curSum;
        }
        return bigSum;
    }
};
