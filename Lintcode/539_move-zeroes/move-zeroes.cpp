/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: C++
@Datetime: 17-04-10 12:02
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        int first = nums.size(), last = nums.size(), size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                first = i;
                break;
            }
        }
        for (int i = first+1; i < size; i++) {
            if (nums[i] != 0) {
                last = i;
                break;
            }
        }
        while (last < size && last > first) {
            int temp = nums[first];
            nums[first] = nums[last];
            nums[last] = temp;
            for (int i = first+1; i < size; i++) {
                if (nums[i] == 0) {
                    first = i;
                    break;
                }
            }
            for (int i = first+1; i < size; i++) {
                if (nums[i] != 0) {
                    last = i;
                    break;
                }
            }
        }
    }
};