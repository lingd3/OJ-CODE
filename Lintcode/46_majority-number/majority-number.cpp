/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 17-03-11 08:08
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int count = 1;
        int n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                n = nums[i];
                count = 1;
            }
            else if (nums[i] == n) count++;
            else count--;
        }
        return n;
    }
};
