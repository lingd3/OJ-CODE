/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 17-02-25 09:38
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1) return;
        int even = 0, odd = nums.size()-1;
        while (even < odd) {
            while (nums[even]%2 != 0 && even < odd) even++;
            while (nums[odd]%2 == 0 && even < odd) odd--;
            int temp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = temp;
        }
    }
};