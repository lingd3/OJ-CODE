/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 17-04-18 09:48
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int low = 0, high = A.size()-1;
        while (low <= high) {
            int mid = (low+high)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};