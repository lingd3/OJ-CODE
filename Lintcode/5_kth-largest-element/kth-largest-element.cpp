/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 17-03-11 08:38
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int start = 0, end = nums.size()-1;
        int index = Partition(nums, start, end);
        int n = nums.size();
        while (index != n-k) {
            if (index > n-k) {
                end = index-1;
                index = Partition(nums, start, end);
            }
            else {
                start = index+1;
                index = index = Partition(nums, start, end);;
            }
        }
        return nums[index];
    }
    
    int Partition(vector<int>& nums, int start, int end) {
        swap(nums, start, (start+end)/2);
        int num = nums[start];
        int last_small = start;
        for (int i = start+1; i <= end; i++) {
            if (nums[i] < num) {
                last_small++;
                swap(nums, last_small, i);
            }
        }
        swap(nums, start, last_small);
        return last_small;
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int n = nums[i];
        nums[i] = nums[j];
        nums[j] = n;
    }
    
};
