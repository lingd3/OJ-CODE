/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: C++
@Datetime: 17-02-25 07:50
*/

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int l = 0, r = nums.size()-1;
        if (nums[l] < nums[r]) return nums[l];
        while (l < r) {
            int mid = (l+r)/2;
            if (nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }
        return nums[l];
        
    }
};