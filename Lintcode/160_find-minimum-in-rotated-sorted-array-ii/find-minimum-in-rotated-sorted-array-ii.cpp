/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 17-02-26 08:00
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int left = 0, right = num.size()-1;
        int mid;
        while (num[left] >= num[right]) {
            if (right-left == 1) return num[right];
            mid = (left+right)/2;
            if (num[left] == num[mid] && num[mid] == num[right]) {
                return findInorder(num, left, right);
            }
            else if (num[mid] >= num[left]) {
                left = mid;
            }
            else if (num[mid] < num[left]) {
                right = mid;
            }
        }
        return num[mid];        
    }
    
    int findInorder(vector<int> &num, int left, int right) {
        int min = num[left];
        for (int i = left; i < right; i++) {
            if (min > num[i]) {
                min = num[i];
            }
        }
        return min;
    }
    
};