/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 16-08-02 12:04
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[(nums.size()-1)/2];
    }
};
