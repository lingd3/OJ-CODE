/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 17-04-18 09:44
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int low = 0, high = array.size()-1;
        while (low < high) {
            int mid = (low+high)/2;
            if (array[mid] < target) low = mid+1;
            else high = mid;
        }
        if (low > high) return -1;
        if (array[low] == target) return low;
        return -1;
    }
};