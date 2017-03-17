/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 17-03-17 08:02
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int a[2], b[2];
        a[0] = nums[0];
        b[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != a[0]) {
                a[1] = nums[i];
                b[1] = 0;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == a[0]) b[0]++;
            else if (nums[i] == a[1]) b[1]++;
            else {
                if (b[0] < b[1]) {
                    if (b[0] == 1) {
                        a[0] = nums[i];
                        b[0] = 0;
                    }
                    else b[0]--;
                }
                else if (b[0] > b[1]) {
                    if (b[1] == 1) {
                        a[1] = nums[i];
                        b[1] = 0;
                    }
                    else b[1]--;
                }
            }
        }
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == a[0]) count1++;
            else if (nums[i] == a[1]) count2++;
        }
        if (count1 > count2) return a[0];
        return a[1];
    }
};





