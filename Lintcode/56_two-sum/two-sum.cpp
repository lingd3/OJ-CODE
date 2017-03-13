/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 17-03-13 14:03
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &num, int target) {  //使用map能达到O(n)
        // write your code here
        vector<int> nums;
        for (int i = 0; i < num.size(); i++) {
            nums.push_back(num[i]);
        }
        vector<int> v;
        quick_sort(nums, 0, nums.size()-1);
        int i = 0, j = nums.size()-1;
        for (; i < j;) {
            if (nums[i] + nums[j] == target) {
                for (int k = 0; k < num.size(); k++) {
                    if (nums[i] == num[k]) v.push_back(k+1);
                    else if (nums[j] == num[k]) v.push_back(k+1);
                }
                break;
            }
            else if (nums[i] + nums[j] < target) i++;
            else j--;
        }
        return v;
    }
    
    void quick_sort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pivot_position = partition(nums, low, high);
            quick_sort(nums, low, pivot_position-1);
            quick_sort(nums, pivot_position+1, high);
        }
    }
    
    int partition(vector<int> &nums, int low, int high) {
        swap(nums, low, (low+high)/2);
        int pivot = nums[low];
        int last_small = low;
        for (int i = low+1; i <= high; i++) {
            if (nums[i] < pivot) {
                last_small++;
                swap(nums, last_small, i);
            }
        }
        swap(nums, last_small, low);
        return last_small;
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
};

